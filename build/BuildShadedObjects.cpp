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
    int num_samples = 16;

    vp.set_hres(400);
    vp.set_vres(400);
    vp.set_samples(num_samples);

    tracer_ptr = new RayCast(this);

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(1, 2, 5);
    pinhole_ptr->set_lookat(0, -0.35, 0);
    pinhole_ptr->set_view_distance(900);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    PointLight* light_ptr1 = new PointLight;
    light_ptr1->set_location(20, 15, 15);
    light_ptr1->scale_radiance(3.0);
    light_ptr1->set_shadows(true);
    add_light(light_ptr1);

    Phong* phong_ptr = new Phong;
    phong_ptr->set_ka(0.3);
    phong_ptr->set_kd(0.5);
    phong_ptr->set_cd(0.15, 0.75, 0.90);
    phong_ptr->set_ks(0.1);
    phong_ptr->set_exp(20.0);

    double inner_radius = 0.9;
    double outer_radius = 1.0;

    FlatRimmedBowl* bowl_ptr = new FlatRimmedBowl(inner_radius, outer_radius);
    bowl_ptr->set_material(phong_ptr);
    add_object(bowl_ptr);

//    Checker3D* checker_ptr = new Checker3D;
//    checker_ptr->set_size(1.0);
//    checker_ptr->set_color1(white);
//    checker_ptr->set_color2(0.75);

    /*SV_*/Matte* sv_matte_ptr = new /*SV_*/Matte;
    sv_matte_ptr->set_ka(0.35);
    sv_matte_ptr->set_kd(0.85);
    sv_matte_ptr->set_cd(0.75);

    Plane* plane_ptr1 = new Plane(Point3D(0, -1, 0), Normal(0, 1, 0));
    plane_ptr1->set_material(sv_matte_ptr);
    add_object(plane_ptr1);
}
