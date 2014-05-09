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
#include "Grid.h"

#include <iostream>

void World::build(void) {
  int num_samples = 1;

    vp.set_hres(400);
    vp.set_vres(400);
    vp.set_samples(num_samples);

    tracer_ptr = new RayCast(this);

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0, 0, 20);
    pinhole_ptr->set_lookat(0, 0, 0);
    pinhole_ptr->set_view_distance(3600);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    Directional* light_ptr = new Directional;
    light_ptr->set_direction(-10, 20, 20);
    light_ptr->scale_radiance(3.0);
    light_ptr->set_shadows(false);
    add_light(light_ptr);

    int num_spheres = 1000;			// for Figure 22.11(a)
  //	int num_spheres = 10000;		// for Figure 22.11(b)
  //	int num_spheres = 100000;		// for Figure 22.11(c)
  //	int num_spheres = 1000000;		// for Figure 22.11(d)

    float volume = 0.1 / num_spheres;
    float radius = pow(0.75 * volume / 3.14159, 0.333333);

    set_rand_seed(15);

    Grid* grid_ptr = new Grid;

    for (int j = 0; j < num_spheres; j++) {
      Matte* matte_ptr = new Matte;
      matte_ptr->set_ka(0.25);
      matte_ptr->set_kd(0.75);
      matte_ptr->set_cd(rand_float(), rand_float(), rand_float());

      Sphere*	sphere_ptr = new Sphere;
      sphere_ptr->set_radius(radius);
      sphere_ptr->set_center(	1.0 - 2.0 * rand_float(),
                  1.0 - 2.0 * rand_float(),
                  1.0 - 2.0 * rand_float());
      sphere_ptr->set_material(matte_ptr);
      grid_ptr->add_object(sphere_ptr);
    }

    grid_ptr->setup_cells();
    add_object(grid_ptr);
}
