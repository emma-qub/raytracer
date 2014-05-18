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
#include "Image.h"
#include "SphericalMap.h"
#include "ImageTexture.h"
#include "SV_Matte.h"

#include <iostream>

void World::build(void) {
  int num_samples = 1;      	// for Figures 29.19(a) & (b)
//	int num_samples = 25;      	// for Figure 29.19(c)

  vp.set_hres(300);
  vp.set_vres(300);
  vp.set_samples(num_samples);

  background_color = black;

  tracer_ptr = new RayCast(this);

  Pinhole* camera_ptr = new Pinhole;
  camera_ptr->set_eye(0, 0, 65);
  camera_ptr->set_lookat(0.0);
  camera_ptr->set_view_distance(9000.0);			// for Figure 29.19(a)
//	camera_ptr->set_view_distance(9000.0 * 8.0);	// for Figure 29.19(b)
//	camera_ptr->set_view_distance(9000.0 * 20.0);	// for Figure 29.19(c)
  camera_ptr->compute_uvw();
  set_camera(camera_ptr);


  Directional* light_ptr = new Directional;
  light_ptr->set_direction(-0.25, 0.4, 1);
  light_ptr->scale_radiance(2.5);
  add_light(light_ptr);


  // image:

  Image* image_ptr = new Image;
  image_ptr->read_ppm_file("../raytracer/Resources/Earth.ppm");


  // mapping:

  SphericalMap* map_ptr = new SphericalMap;


  // image based texture:

  ImageTexture* texture_ptr = new ImageTexture;
  texture_ptr->set_image(image_ptr);
  texture_ptr->set_mapping(map_ptr);


  // textured material:

  SV_Matte* sv_matte_ptr = new SV_Matte;
  sv_matte_ptr->set_ka(0.2);
  sv_matte_ptr->set_kd(0.8);
  sv_matte_ptr->set_cd(texture_ptr);


  // generic sphere:

  Sphere*	sphere_ptr = new Sphere;
  sphere_ptr->set_material(sv_matte_ptr);


  // rotated sphere

  Instance* earth_ptr = new Instance(sphere_ptr);
  earth_ptr->rotate_y(-72);
  earth_ptr->rotate_x(40);
  earth_ptr->rotate_z(20);
  add_object(earth_ptr);
}
