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
#include "Grid.h"
#include "Whitted.h"
#include "GlossyReflector.h"
#include "AreaLighting.h"
#include "AreaLight.h"
#include "Emissive.h"
#include "PerfectTransmitter.h"
#include "Transparent.h"

#include <iostream>

void World::build(void) {
  int num_samples = 9;

  vp.set_hres(600);
  vp.set_vres(600);
  vp.set_samples(num_samples);
  vp.set_max_depth(5);

  background_color = RGBColor(0.0, 0.3, 0.25);

  tracer_ptr = new Whitted(this);

  Ambient* ambient_ptr = new Ambient;
  ambient_ptr->scale_radiance(0.25);
  set_ambient_light(ambient_ptr);

  Pinhole* pinhole_ptr = new Pinhole;
  pinhole_ptr->set_eye(-8, 5.5, 20);
  pinhole_ptr->set_lookat(0, 4.5, 0);
  pinhole_ptr->set_view_distance(1400.0);
  pinhole_ptr->compute_uvw();
  set_camera(pinhole_ptr);


  // point light

  PointLight* light_ptr1 = new PointLight;
  light_ptr1->set_location(40, 50, 0);
  light_ptr1->scale_radiance(4.5);
  light_ptr1->set_shadows(true);
  add_light(light_ptr1);


  // point light

  PointLight* light_ptr2 = new PointLight;
  light_ptr2->set_location(-10, 20, 10);
  light_ptr2->scale_radiance(4.5);
  light_ptr2->set_shadows(true);
  add_light(light_ptr2);


  // directional light

  Directional* light_ptr3 = new Directional;
  light_ptr3->set_direction(-1, 0, 0);
  light_ptr3->scale_radiance(4.5);
  light_ptr3->set_shadows(true);
  add_light(light_ptr3);


  // transparent torus

  Transparent* glass_ptr = new Transparent;
  glass_ptr->set_ks(0.2);
  glass_ptr->set_exp(2000.0);
  glass_ptr->set_ior(1.5);
  glass_ptr->set_kr(0.1);
  glass_ptr->set_kt(0.9);

  Instance* torus_ptr2 = new Instance (new Torus(3.0, 0.8));
  torus_ptr2->set_material(glass_ptr);
  torus_ptr2->rotate_x(90);
  torus_ptr2->rotate_y(20);
  torus_ptr2->translate(0, 4.5, 0);
  add_object(torus_ptr2);


  // red sphere

  Reflective*	reflective_ptr = new Reflective;
  reflective_ptr->set_ka(0.3);
  reflective_ptr->set_kd(0.3);
  reflective_ptr->set_cd(red);
  reflective_ptr->set_ks(0.2);
  reflective_ptr->set_exp(2000.0);
  reflective_ptr->set_kr(0.25);

  Sphere* sphere_ptr2 = new Sphere(Point3D(4, 4, -6), 3);
  sphere_ptr2->set_material(reflective_ptr);
  add_object(sphere_ptr2);


//  Checker3D* checker_ptr = new Checker3D;
//  checker_ptr->set_size(4.0);
//  checker_ptr->set_color1(0.75);
//  checker_ptr->set_color2(white);

  /*SV_*/Matte* sv_matte_ptr = new /*SV_*/Matte;
  sv_matte_ptr->set_ka(0.5);
  sv_matte_ptr->set_kd(0.35);
  sv_matte_ptr->set_cd(0.75);


  // rectangle

  Point3D p0(-20, 0, -100);
  Vector3D a(0, 0, 120);
  Vector3D b(40, 0, 0);

  Rectangle* rectangle_ptr = new Rectangle(p0, a, b);
  rectangle_ptr->set_material(sv_matte_ptr);
  add_object(rectangle_ptr);
}
