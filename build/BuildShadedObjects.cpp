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
#include "Pinhole.h"
#include "ThinLens.h"
#include "StereoCamera.h"
#include "Fisheye.h"
#include "Spherical.h"

#include <iostream>

void World::build(void) {
  //int num_samples = 1;   	// for Figure 17.4(a)
  //int num_samples = 16;  	// for Figure 17.4(b)
  //int num_samples = 64;  	// for Figure 17.4(c)
  int num_samples = 256;	// for Figure 17.4(d)

  vp.set_hres(400);
  vp.set_vres(400);
  vp.set_samples(num_samples);

  tracer_ptr = new RayCast(this);

  AmbientOccluder* occluder_ptr = new AmbientOccluder;
  occluder_ptr->set_samples(num_samples);
  occluder_ptr->scale_radiance(1.0);
  occluder_ptr->set_min_amount(0.0);
  set_ambient_light(occluder_ptr);


  Pinhole* pinhole_ptr = new Pinhole;
  pinhole_ptr->set_eye(25, 20, -45);
  pinhole_ptr->set_lookat(0, 1, 0);
  pinhole_ptr->set_view_distance(5000);
  pinhole_ptr->compute_uvw();
  set_camera(pinhole_ptr);

  // sphere

  Matte* matte_ptr1 = new Matte;
  matte_ptr1->set_ka(0.75);
  matte_ptr1->set_kd(0);
  matte_ptr1->set_cd(1, 1, 0);   // yellow

  Sphere* sphere_ptr = new Sphere (Point3D(0, 1, 0), 1);
  sphere_ptr->set_material(matte_ptr1);
  add_object(sphere_ptr);

  // ground plane

  Matte* matte_ptr2 = new Matte;
  matte_ptr2->set_ka(0.75);
  matte_ptr2->set_kd(0);
  matte_ptr2->set_cd(white);

  Plane* plane_ptr = new Plane(Point3D(0), Normal(0, 1, 0));
  plane_ptr->set_material(matte_ptr2);
  add_object(plane_ptr);
}
