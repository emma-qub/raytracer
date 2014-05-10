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
//#include "Orthographic.h"
#include "Grid.h"
#include "Whitted.h"

#include <iostream>

void World::build(void) {
  int num_samples = 25;

    vp.set_hres(600);
    vp.set_vres(600);
    vp.set_samples(num_samples);

    tracer_ptr = new RayCast(this);

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(7, 5, 4.5);
    pinhole_ptr->set_lookat(0, -0.5, -0.25);
    pinhole_ptr->set_view_distance(1305);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);


    Directional* light_ptr1 = new Directional;
    light_ptr1->set_direction(1, 0, 0);    				// from the +ve x direction
    light_ptr1->scale_radiance(1);
    light_ptr1->set_shadows(true);
    add_light(light_ptr1);

    Directional* light_ptr2 = new Directional;
    light_ptr2->set_direction(0, 1, 0);    				// from the +ve y direction
    light_ptr2->scale_radiance(2);
    light_ptr2->set_shadows(true);
    add_light(light_ptr2);

    Directional* light_ptr3 = new Directional;
    light_ptr3->set_direction(0, 0, 1);    				// from the +ve z direction
    light_ptr3->scale_radiance(1.5);
    light_ptr3->set_shadows(true);
    add_light(light_ptr3);

    Grid* grid_ptr = new Grid;

    int num_spheres = 25;
    float volume = 0.1 / num_spheres;
    float radius = 2.5 * pow(0.75 * volume / 3.14159, 0.333333);

    set_rand_seed(15);

    for (int j = 0; j < num_spheres; j++) {
//      SphereChecker* checker_ptr = new SphereChecker;
//      checker_ptr->set_numlong(16);
//      checker_ptr->set_numlat(8);
//      checker_ptr->set_line_width(0.075);

      RGBColor color(rand_float(), rand_float(), rand_float());
//      checker_ptr->set_color1(color);
//      checker_ptr->set_color2(color);
//      checker_ptr->set_line_color(black);

      /*SV_*/Matte* sv_matte_ptr1 = new /*SV_*/Matte;
      sv_matte_ptr1->set_ka(0.5);
      sv_matte_ptr1->set_kd(0.6);
      sv_matte_ptr1->set_cd(/*checker_ptr*/color);

      Sphere* sphere_ptr1 = new Sphere;
      sphere_ptr1->set_material(sv_matte_ptr1);

      Instance* sphere_ptr2 = new Instance(sphere_ptr1);
      sphere_ptr2->scale(radius);
      sphere_ptr2->translate(1.0 - 2.0 * rand_float(), 1.0 - 2.0 * rand_float(), 1.0 - 2.0 * rand_float());
      //sphere_ptr2->set_bounding_box();
      grid_ptr->add_object(sphere_ptr2);
    }

    grid_ptr->setup_cells();
    add_object(grid_ptr);

    // plane perpendicular to x axis

    Matte* matte_ptr1 = new Matte;
    matte_ptr1->set_ka(0.15);
    matte_ptr1->set_kd(0.6);
    matte_ptr1->set_cd(0.5);

    Plane* plane_ptr1 = new Plane(Point3D(-2, 0, 0), Normal(1, 0, 0));
    plane_ptr1->set_material(matte_ptr1);
    add_object(plane_ptr1);

    // plane perpendicular to y axis

    Matte* matte_ptr2 = new Matte;
    matte_ptr2->set_ka(0.15);
    matte_ptr2->set_kd(0.6);
    matte_ptr2->set_cd(0.5);

    Plane* plane_ptr2 = new Plane(Point3D(0, -2, 0), Normal(0, 1, 0));
    plane_ptr2->set_material(matte_ptr2);
    add_object(plane_ptr2);

    // plane perpendicular to z axis

    Matte* matte_ptr3 = new Matte;
    matte_ptr3->set_ka(0.15);
    matte_ptr3->set_kd(0.6);
    matte_ptr3->set_cd(0.5);

    Plane* plane_ptr3 = new Plane(Point3D(0, 0, -2), Normal(0, 0, 1));
    plane_ptr3->set_material(matte_ptr3);
    add_object(plane_ptr3);
}
