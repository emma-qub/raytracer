// This builds a scene that consists of 35 shaded spheres and a plane.
// The objects are illuminated by a directional light and rendered with
// ambient and diffuse shading.
// Perspective viewing is used with a pinhole camera.
// Jittered sampling for antialiasing is hardwired into the PinHole::render_scene function.
// There are no sampler classes in this project.
// These are in the Chapter 5 download file.
// The spheres are the same as those in the Chapter 14 page one image.

#include "World.h"
#include "AmbientOccluder.h"
#include "Matte.h"
#include "Phong.h"
#include "Reflective.h"
#include "Pinhole.h"
#include "ThinLens.h"
#include "StereoCamera.h"
#include "Fisheye.h"
#include "Spherical.h"
//#include "Orthographic.h"
#include "Whitted.h"
#include "SV_Matte.h"
#include "Emissive.h"
#include "AreaLighting.h"
#include "Transparent.h"
#include "SingleSphere.h"
#include "GlossyReflector.h"
#include "CubicNoise.h"
#include "FBmTexture.h"
#include "LegoPart.h"

#include <iostream>
#include <QDebug>

std::string path("../raytracer/Resources/TextureFiles/ppm/CloudsLowResWithBlack.ppm");

void World::build(void) {
  int num_samples = 1;

  vp.set_hres(600);
  vp.set_vres(400);
  vp.set_samples(num_samples);

  background_color = white;

  tracer_ptr = new RayCast(this);

  Pinhole* camera_ptr = new Pinhole;

  // for Figure 16.5(a)

  camera_ptr->set_eye(35, 50, 35);
  camera_ptr->set_lookat(0, 0, 0);
  camera_ptr->set_view_distance(350);

  camera_ptr->compute_uvw();
  set_camera(camera_ptr);


  PointLight* light_ptr = new PointLight;
  light_ptr->set_location(1500, 750, 250);
  light_ptr->scale_radiance(4.5);
  light_ptr->set_shadows(true);
  add_light(light_ptr);


  // lego material

  Matte* matte_ptr3 = new Matte;
  matte_ptr3->set_cd(0.5, 0.6, 0);     // green
  matte_ptr3->set_ka(0.4);
  matte_ptr3->set_kd(0.5);

  LegoPart* lego = new LegoPart("/home/valentin/Documents/ldraw/parts/62712.dat");
  lego->set_material(matte_ptr3->clone());
  add_object(lego);

  // ground plane with checker

  Checker3D* checker_ptr = new Checker3D;
  checker_ptr->set_size(10);
  checker_ptr->set_color1(0.7);
  checker_ptr->set_color2(white);

  SV_Matte* sv_matte_ptr1 = new SV_Matte;
  sv_matte_ptr1->set_ka(0.15);
  sv_matte_ptr1->set_kd(1.0);
  sv_matte_ptr1->set_cd(checker_ptr);
  Plane* plane_ptr = new Plane(Point3D(0, -20, 0), Normal(0, 1, 0));
  plane_ptr->set_material(sv_matte_ptr1->clone());
  add_object(plane_ptr);
}
