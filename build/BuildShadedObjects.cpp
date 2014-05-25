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

#include <iostream>
#include <QDebug>

std::string path("../raytracer/Resources/TextureFiles/ppm/CloudsLowResWithBlack.ppm");

void World::build(void) {
  int num_samples = 1;

  vp.set_hres(600);
  vp.set_vres(600);
  vp.set_samples(num_samples);
  vp.set_gamut_display(true);

  background_color = black;
  tracer_ptr = new RayCast(this);

  Pinhole* pinhole_ptr = new Pinhole;
  pinhole_ptr->set_eye(0, 0, 100);
  pinhole_ptr->set_lookat(0);
  pinhole_ptr->set_view_distance(6000.0);
  pinhole_ptr->compute_uvw();
  set_camera(pinhole_ptr);


  Directional* light_ptr = new Directional;
  light_ptr->set_direction(0, 0, 1);
  light_ptr->scale_radiance(2.5);
  add_light(light_ptr);

  // noise:

  CubicNoise* noise_ptr = new CubicNoise;
//  noise_ptr->set_num_octaves(1);				// for Figure 31.21(a)
//  noise_ptr->set_num_octaves(2);				// for Figure 31.21(b)
//  noise_ptr->set_num_octaves(3);				// for Figure 31.21(c)
  noise_ptr->set_num_octaves(8);				// for Figure 31.21(c)
  noise_ptr->set_gain(0.5);
  noise_ptr->set_lacunarity(2.0);

  // texture:

  FBmTexture* texture_ptr = new FBmTexture(noise_ptr);
  texture_ptr->set_color(white);
  texture_ptr->set_min_value(0.0);
  texture_ptr->set_max_value(1.0);


  // material:

  SV_Matte* sv_matte_ptr = new SV_Matte;
  sv_matte_ptr->set_ka(0.25);
  sv_matte_ptr->set_kd(0.85);
  sv_matte_ptr->set_cd(texture_ptr);

  Plane* plane_ptr1 = new Plane(Point3D(0.0), Normal(0, 0, 1));
  plane_ptr1->set_material(sv_matte_ptr->clone());
  add_object(plane_ptr1);
}



