// This builds a scene that consists of 35 shaded spheres and a plane.
// The objects are illuminated by a directional light and rendered with
// ambient and diffuse shading.
// Perspective viewing is used with a pinhole camera.
// Jittered sampling for antialiasing is hardwired into the PinHole::render_scene function.
// There are no sampler classes in this project.
// These are in the Chapter 5 download file.
// The spheres are the same as those in the Chapter 14 page one image.

#include "World.h"
#include "RayCast.h"
#include "MultipleObjects.h"
#include "Directional.h"
#include "PointLight.h"
#include "Matte.h"
#include "Phong.h"
#include "Plane.h"
#include "Pinhole.h"
#include "ThinLens.h"
#include "StereoCamera.h"
#include "Fisheye.h"
#include "Spherical.h"
#include "Maths.h"

#define chocolate 0
#define chapitre11_1 0
#define chapitre11_2 0
#define chapitre15_7 1
#define firstexample 0

#include <iostream>

void World::build(void) {

#if chapitre15_7
  int num_samples = 1;

  vp.set_hres(650);
  vp.set_vres(300);
  vp.set_samples(num_samples);

  tracer_ptr = new RayCast(this);

  Pinhole* pinhole_ptr = new Pinhole;
  pinhole_ptr->set_eye(0, 0, 100);
  pinhole_ptr->set_lookat(0, 0, 0);
  pinhole_ptr->set_view_distance(6000);
  pinhole_ptr->compute_uvw();
  set_camera(pinhole_ptr);

  Directional* light_ptr2 = new Directional;
  light_ptr2->set_direction(20, 0, 20);
  light_ptr2->scale_radiance(3.0);
  add_light(light_ptr2);


  // beveled cylinder

  float bottom 		= -2.0;
  float top 			= 2.0;
  float radius 		= 1.0;
  //float bevel_radius 	= 0.2;

  //BeveledCylinder* cylinder_ptr1 = new BeveledCylinder(bottom, top, radius, bevel_radius);
  SolidCylinder* cylinder_ptr1 = new SolidCylinder(bottom, top, radius);

  for (int j = 0; j < 4; j++) {
    float exp;

    if (j == 0) exp = 5;
    if (j == 1) exp = 20;
    if (j == 2) exp = 100;
    if (j == 3) exp = 1000;

    Phong* phong_ptr = new Phong;
    phong_ptr->set_ka(0.25);
    phong_ptr->set_kd(0.6);
    phong_ptr->set_cd(0.5);
    phong_ptr->set_ks(0.2);
    phong_ptr->set_exp(exp);

    Instance* cylinder_ptr2 = new Instance(cylinder_ptr1);
    cylinder_ptr2->translate(-3.75 + 2.5 * j, 0, 0);
    cylinder_ptr2->set_material(phong_ptr);
    add_object(cylinder_ptr2);
  }
#endif

#if chocolate
  int num_samples = 100;

  Matte* matte_ptr1 = new Matte;
  matte_ptr1->set_ka(ka);
  matte_ptr1->set_kd(kd);
  matte_ptr1->set_cd(brown);
  Matte* matte_ptr2 = new Matte;
  matte_ptr2->set_ka(ka);
  matte_ptr2->set_kd(kd);
  matte_ptr2->set_cd(brown);
  Matte* matte_ptr3 = new Matte;
  matte_ptr3->set_ka(ka);
  matte_ptr3->set_kd(kd);
  matte_ptr3->set_cd(brown);
  Matte* matte_ptr4 = new Matte;
  matte_ptr4->set_ka(ka);
  matte_ptr4->set_kd(kd);
  matte_ptr4->set_cd(brown);
  Matte* matte_ptr5 = new Matte;
  matte_ptr5->set_ka(ka);
  matte_ptr5->set_kd(kd);
  matte_ptr5->set_cd(brown);
  Matte* matte_ptr6 = new Matte;
  matte_ptr6->set_ka(ka);
  matte_ptr6->set_kd(kd);
  matte_ptr6->set_cd(brown);
  BeveledBox* beveledBox1 =
    new BeveledBox(Point3D(-50, -5, -40), Point3D(-25, 5, -20), 2);
  BeveledBox* beveledBox2 =
    new BeveledBox(Point3D(-25, -5, -20), Point3D(0, 5, 0), 2);
  BeveledBox* beveledBox3 =
    new BeveledBox(Point3D(-50, -5, -20), Point3D(-25, 5, 0), 2);
  BeveledBox* beveledBox4 =
    new BeveledBox(Point3D(-25, -5, -40), Point3D(0, 5, -20), 2);
  Rectangle* bottom1 = new Rectangle(
    Point3D(-48, -5, 0), Vector3D(48, 0, 0), Vector3D(0, 2, 0));
  Rectangle* bottom2 = new Rectangle(
    Point3D(0, -5, 0), Vector3D(0, 0, -38), Vector3D(0, 2, 0));
  beveledBox1->set_material(matte_ptr1);	   							// brown
  beveledBox2->set_material(matte_ptr2);	   							// brown
  beveledBox3->set_material(matte_ptr3);	   							// brown
  beveledBox4->set_material(matte_ptr4);	   							// brown
  bottom1->set_material(matte_ptr5);
  bottom2->set_material(matte_ptr6);
  add_object(beveledBox1);
  add_object(beveledBox2);
  add_object(beveledBox3);
  add_object(beveledBox4);
  add_object(bottom1);
  add_object(bottom2);
#endif

#if chapitre11_1
  int num_samples = 16;

  vp.set_hres(600);
  vp.set_vres(600);
  vp.set_samples(num_samples);

  tracer_ptr = new RayCast(this);

  // pinhole camera for Figure 11.7(a)

  Pinhole* pinHole_ptr = new Pinhole;
  pinHole_ptr->set_eye(250, 300, 150);
  pinHole_ptr->set_lookat(-20, 300, -110);
  pinHole_ptr->set_view_distance(250);
  pinHole_ptr->compute_uvw();
  //	set_camera(pinHole_ptr);


  // fisheye camera for the other parts

  Fisheye* fisheye_ptr = new Fisheye;

  //fisheye_ptr->set_rectangular(true);

  // for parts (b), (c), (d)

  fisheye_ptr->set_eye(250, 300, 150);
  fisheye_ptr->set_lookat(-20, 300, -110);
  //fisheye_ptr->set_fov(120);  // part (b)
  //fisheye_ptr->set_fov(180);  // part (c)
  //fisheye_ptr->set_fov(360);  // part (d)


  // for part (e)
  fisheye_ptr->set_eye(250, 450, 150);
  fisheye_ptr->set_lookat(-20, 250, -110);
  fisheye_ptr->set_fov(360);


  /*
  // for part (f)
  // for this image the skydome is the only object in the scene
  // you need to comment out the two statements:
  // add_object(grid_ptr);
  // add_object(plane_ptr);

  fisheye_ptr->set_eye(0, 0, 0);
  fisheye_ptr->set_lookat(0, 1, 0);
  fisheye_ptr->set_fov(180);
  */

  fisheye_ptr->compute_uvw();
  set_camera(fisheye_ptr);

  PointLight* light_ptr1 = new PointLight;
  light_ptr1->set_location(150, 200, 65);
  light_ptr1->scale_radiance(5.25);
  //light_ptr1->set_shadows(true);
  add_light(light_ptr1);


  // box materials

  Matte* matte_ptr1 = new Matte;
  matte_ptr1->set_cd(0, 0.5, 0.5);     // cyan
  matte_ptr1->set_ka(0.4);
  matte_ptr1->set_kd(0.5);

  Matte* matte_ptr2 = new Matte;
  matte_ptr2->set_cd(1, 0, 0);     	  // red
  matte_ptr2->set_ka(0.4);
  matte_ptr2->set_kd(0.5);

  Matte* matte_ptr3 = new Matte;
  matte_ptr3->set_cd(0.5, 0.6, 0);     // green
  matte_ptr3->set_ka(0.4);
  matte_ptr3->set_kd(0.5);

  // Construct rows of boxes stored in a grid
  // Grid* grid_ptr = new Grid;

  // first row
  int num_boxes = 40;
  float wx = 50;
  float wz = 50;
  float h = 150;
  float s = 100;

  for (int j = 0; j < num_boxes; j++) {
    Box* box_ptr = new Box(	Point3D(-wx, 0, -(j + 1) * wz - j * s),
                Point3D(0, h, - j * wz - j * s));
    box_ptr->set_material(matte_ptr1->clone());
    //add_object(box_ptr);
    //grid_ptr->add_object(box_ptr);
    add_object(box_ptr);
  }

  // second row
  h = 300;
  for (int j = 0; j < num_boxes; j++) {
    Box* box_ptr = new Box(	Point3D(-wx -wx - s, 0, -(j + 1) * wz - j * s),
                Point3D(-wx - s, h, - j * wz - j * s));
    box_ptr->set_material(matte_ptr2->clone());
    //add_object(box_ptr);
    //grid_ptr->add_object(box_ptr);
    add_object(box_ptr);
  }

  // third row
  h = 850;
  for (int j = 0; j < num_boxes; j++) {
    Box* box_ptr = new Box(	Point3D(-wx - 2 * wx - 2 * s, 0, -(j + 1) * wz - j * s),
                Point3D(-2 * wx - 2 * s, h, - j * wz - j * s));
    box_ptr->set_material(matte_ptr3->clone());
    //add_object(box_ptr);
    //grid_ptr->add_object(box_ptr);
    add_object(box_ptr);
  }

  // a column
  h = 150;
  for (int j = 0; j < num_boxes; j++) {
    Box* box_ptr = new Box(	Point3D(-3 * (wx + s) - (j + 1) * wz - j * s, 0, -wx),
                Point3D(-3 * (wx + s) - j * wz - j * s, h, 0));
    box_ptr->set_material(matte_ptr1->clone());
    //add_object(box_ptr);
    //grid_ptr->add_object(box_ptr);
    add_object(box_ptr);
  }

  //grid_ptr->setup_cells();
  //add_object(grid_ptr);

  // ground plane with checker

  //Checker3D* checker_ptr = new Checker3D;
  //Plane* checker_ptr = new Plane;
  //checker_ptr->set_size(2 * wx);
  //checker_ptr->set_color1(0.7);
  //checker_ptr->set_color2(white);

  Matte* sv_matte_ptr1 = new Matte;
  sv_matte_ptr1->set_cd(0.5, 0.5, 0.5);
  sv_matte_ptr1->set_ka(0.20);
  sv_matte_ptr1->set_kd(0.50);
  //sv_matte_ptr1->set_cd(checker_ptr);
  Plane* plane_ptr = new Plane(Point3D(0, 1, 0), Normal(0, 1, 0));
  plane_ptr->set_material(sv_matte_ptr1);
  add_object(plane_ptr);
#endif

#if chapitre11_2
  // 	Copyright (C) Kevin Suffern 2000-2007.
  //	This C++ code is for non-commercial purposes only.
  //	This C++ code is licensed under the GNU General Public License Version 2.
  //	See the file COPYING.txt for the full license.

  // This builds the scene for Figure 11.12
  // The light probe mapping is described in Chapter 29
  // There are no light sources in this scene

  int num_samples = 16;

  vp.set_hres(600);
  vp.set_vres(600);
  vp.set_samples(num_samples);
  vp.set_pixel_size(1.0);

  tracer_ptr = new RayCast(this);

  Spherical* spherical_ptr = new Spherical;
  spherical_ptr->set_eye(10, 15, 13);
  spherical_ptr->set_lookat(34, 15, 0);

  /*
  // for Figure 11.12(a)

  vp.set_hres(600);
  vp.set_vres(400);

  spherical_ptr->set_horizontal_fov(180);
  spherical_ptr->set_vertical_fov(120);
  */


  // for Figure 11.12(b)

  vp.set_hres(800);
  vp.set_vres(400);

  spherical_ptr->set_horizontal_fov(360);
  spherical_ptr->set_vertical_fov(180);

  spherical_ptr->compute_uvw();
  set_camera(spherical_ptr);


  PointLight* light_ptr2 = new PointLight;
  light_ptr2->set_location(150, 500, 300);
  light_ptr2->scale_radiance(3.75);
  //light_ptr2->set_shadows(true);
  add_light(light_ptr2);


  // city parameters

  float 	a					= 10;   // city block width:  xw extent
  float 	b   				= 12;	// city block length:  yw extent
  int 	num_rows			= 10;  	// number of blocks in the xw direction
  int 	num_columns			= 12; 	// number of blocks in the zw direction
  float	width				= 7;	// building width: xw extent in range [min, a - offset]
  float 	length				= 7;	// building length: zw extent in range [min, b - offset]
  float 	min_size			= 6;	// mininum building extent in xw and yw directions
  float 	offset				= 1.0;	// half the minimum distance between buildings
  float 	min_height			= 0.0; 	// minimum building height
  float 	max_height			= 30; 	// maximum bulding height
  float 	height;						// the building height in range [min_height, max_height]
  int		num_park_rows		= 4;  	// number of blocks of park in xw direction
  int		num_park_columns	= 6;  	// number of blocks of park in xw direction
  int 	row_test;					// there are no buildings in the park
  int 	column_test;				// there are no buildings in the park
  float 	min_color			= 0.1;  // prevents black buildings
  float 	max_color			= 0.9;	// prevents white buildings

  set_rand_seed(15);  				// as the buildings' dimensions and colors are random, it's necessary to
                    // seed rand to keep these quantities the same at each run
                    // if you leave this out, and change the number of samples per pixel,
                    // these will change

  // the buildings are stored in a grid

  //Grid* grid_ptr = new Grid;

  for (int r = 0; r < num_rows; r++)  			// xw direction
    for (int c = 0; c < num_columns; c++) {		// zw direction
      // determine if the block is in the park

      if ((r - num_rows / 2) >= 0)
        row_test = r -  num_rows / 2;
      else
        row_test = r -  num_rows / 2 + 1;

      if ((c - num_columns / 2) >= 0)
        column_test = c - num_columns / 2;
      else
        column_test = c - num_columns / 2 + 1;

      if (abs(row_test) >= (num_park_rows / 2) || abs(column_test) >= (num_park_columns / 2)) {

        Matte* matte_ptr = new Matte;
        matte_ptr->set_ka(0.4);
        matte_ptr->set_kd(0.6);
        matte_ptr->set_cd(	min_color + rand_float() * (max_color - min_color),
                  min_color + rand_float() * (max_color - min_color),
                  min_color + rand_float() * (max_color - min_color));

        // block center coordinates

        float xc = a * (r - num_rows / 2.0 + 0.5);
        float zc = b * (c - num_columns / 2.0 + 0.5);

        width = min_size + rand_float() * (a - 2 * offset - min_size);
        length = min_size + rand_float() * (b - 2 * offset - min_size);

        // minimum building coordinates

        float xmin = xc - width / 2.0;
        float ymin = 0.0;
        float zmin = zc - length / 2.0;

        // maximum building coordinates

        height = min_height + rand_float() * (max_height - min_height);

        // The following is a hack to make the middle row and column of buildings higher
        // on average than the other buildings.
        // This only works properly when there are three rows and columns of buildings

        if (r == 1 || r == num_rows - 2 || c == 1 || c == num_columns - 2)
          height *= 1.5;

        float xmax = xc + width / 2.0;
        float ymax = height;
        float zmax = zc + length / 2.0;

        Box* building_ptr = new  Box(Point3D(xmin, ymin, zmin), Point3D(xmax, ymax, zmax));
        building_ptr->set_material(matte_ptr);
        /*grid_ptr->*/add_object(building_ptr);
      }
    }

  //grid_ptr->setup_cells();
  //add_object(grid_ptr);


  // render the park with small green checkers

  Matte* sv_matte_ptr1 = new Matte;
  sv_matte_ptr1->set_ka(0.3);
  sv_matte_ptr1->set_kd(0.50);
  sv_matte_ptr1->set_cd(0.35, 0.75, 0.35);

  //Checker3D* checker3D_ptr1 = new Checker3D;
  Rectangle* checker3D_ptr1 = new Rectangle;
  //checker3D_ptr1->set_size(5);
  //checker3D_ptr1->set_color1(0.35, 0.75, 0.35);
  //checker3D_ptr1->set_color2(0.3, 0.5, 0.3);
  checker3D_ptr1->set_material(sv_matte_ptr1);

  //SV_Matte* sv_matte_ptr1 = new SV_Matte;
  //sv_matte_ptr1->set_ka(0.3);
  //sv_matte_ptr1->set_kd(0.50);
  //sv_matte_ptr1->set_cd(checker3D_ptr1);

  Box* park_ptr = new Box( 	Point3D(-a * num_park_rows / 2, 0.0, -b * num_park_columns / 2),
                Point3D(a * num_park_rows / 2, 0.1, b * num_park_columns / 2)  );
  park_ptr->set_material(sv_matte_ptr1);
  add_object(park_ptr);


  // ground plane with checker:

  Matte* sv_matte_ptr2 = new Matte;
  sv_matte_ptr2->set_ka(0.30);
  sv_matte_ptr2->set_kd(0.40);
  sv_matte_ptr2->set_cd(0.7);

  //Checker3D* checker3D_ptr2 = new Checker3D;
  Rectangle* checker3D_ptr2 = new Rectangle;
  //checker3D_ptr2->set_size(50);
  //checker3D_ptr2->set_color1(RGBColor(0.7));
  //checker3D_ptr2->set_color2(RGBColor(1));
  checker3D_ptr2->set_material(sv_matte_ptr2);

  //SV_Matte* sv_matte_ptr2 = new SV_Matte;
  //sv_matte_ptr2->set_ka(0.30);
  //sv_matte_ptr2->set_kd(0.40);
  //sv_matte_ptr2->set_cd(checker3D_ptr2);

  Plane* plane_ptr = new Plane(Point3D(0, 0.01, 0), Normal(0, 1, 0));
  plane_ptr->set_material(sv_matte_ptr2);
  add_object(plane_ptr);


//  Image* image_ptr = new Image;
//  image_ptr->read_ppm_file("CloudsSmall.ppm");

//  SphericalMap* spherical_map_ptr = new SphericalMap;

//  ImageTexture* image_texture_ptr = new ImageTexture(image_ptr);
//  image_texture_ptr->set_mapping(spherical_map_ptr);

//  SV_Matte* sv_matte_ptr = new SV_Matte;
//  sv_matte_ptr->set_ka(1.0);
//  sv_matte_ptr->set_kd(0.85);
//  sv_matte_ptr->set_cd(image_texture_ptr);

//  Sphere* unit_sphere_ptr = new Sphere;
//  unit_sphere_ptr->set_shadows(false);

//  Instance* sphere_ptr = new Instance(unit_sphere_ptr);
//  sphere_ptr->scale(1000000);
//  sphere_ptr->set_material(sv_matte_ptr);
//  add_object(sphere_ptr);
#endif

#if firstexample

  // spheres

  Matte* matte_ptr1 = new Matte;
  matte_ptr1->set_ka(ka);
  matte_ptr1->set_kd(kd);
  matte_ptr1->set_cd(yellow);
  Sphere*	sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
  sphere_ptr1->set_material(matte_ptr1);	   							// yellow
  add_object(sphere_ptr1);

  Matte* matte_ptr2 = new Matte;
  matte_ptr2->set_ka(ka);
  matte_ptr2->set_kd(kd);
  matte_ptr2->set_cd(brown);
  Sphere*	sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
  sphere_ptr2->set_material(matte_ptr2);								// brown
  add_object(sphere_ptr2);


  Matte* matte_ptr3 = new Matte;
  matte_ptr3->set_ka(ka);
  matte_ptr3->set_kd(kd);
  matte_ptr3->set_cd(darkGreen);
  Sphere*	sphere_ptr3 = new Sphere(Point3D(40, 43, -100), 17);
  sphere_ptr3->set_material(matte_ptr3);								// dark green
  add_object(sphere_ptr3);

  Matte* matte_ptr4 = new Matte;
  matte_ptr4->set_ka(ka);
  matte_ptr4->set_kd(kd);
  matte_ptr4->set_cd(orange);
  Sphere*	sphere_ptr4 = new Sphere(Point3D(-20, 28, -15), 20);
  sphere_ptr4->set_material(matte_ptr4);								// orange
  add_object(sphere_ptr4);

  Matte* matte_ptr5 = new Matte;
  matte_ptr5->set_ka(ka);
  matte_ptr5->set_kd(kd);
  matte_ptr5->set_cd(green);
  Sphere*	sphere_ptr5 = new Sphere(Point3D(-25, -7, -35), 27);
  sphere_ptr5->set_material(matte_ptr5);								// green
  add_object(sphere_ptr5);

  Matte* matte_ptr6 = new Matte;
  matte_ptr6->set_ka(ka);
  matte_ptr6->set_kd(kd);
  matte_ptr6->set_cd(lightGreen);
  Sphere*	sphere_ptr6 = new Sphere(Point3D(20, -27, -35), 25);
  sphere_ptr6->set_material(matte_ptr6);								// light green
  add_object(sphere_ptr6);

  Matte* matte_ptr7 = new Matte;
  matte_ptr7->set_ka(ka);
  matte_ptr7->set_kd(kd);
  matte_ptr7->set_cd(green);
  Sphere*	sphere_ptr7 = new Sphere(Point3D(35, 18, -35), 22);
  sphere_ptr7->set_material(matte_ptr7);   							// green
  add_object(sphere_ptr7);

  Matte* matte_ptr8 = new Matte;
  matte_ptr8->set_ka(ka);
  matte_ptr8->set_kd(kd);
  matte_ptr8->set_cd(brown);
  Sphere*	sphere_ptr8 = new Sphere(Point3D(-57, -17, -50), 15);
  sphere_ptr8->set_material(matte_ptr8);								// brown
  add_object(sphere_ptr8);

  Matte* matte_ptr9 = new Matte;
  matte_ptr9->set_ka(ka);
  matte_ptr9->set_kd(kd);
  matte_ptr9->set_cd(lightGreen);
  Sphere*	sphere_ptr9 = new Sphere(Point3D(-47, 16, -80), 23);
  sphere_ptr9->set_material(matte_ptr9);								// light green
  add_object(sphere_ptr9);

  Matte* matte_ptr10 = new Matte;
  matte_ptr10->set_ka(ka);
  matte_ptr10->set_kd(kd);
  matte_ptr10->set_cd(darkGreen);
  Sphere*	sphere_ptr10 = new Sphere(Point3D(-15, -32, -60), 22);
  sphere_ptr10->set_material(matte_ptr10);     						// dark green
  add_object(sphere_ptr10);

  Matte* matte_ptr11 = new Matte;
  matte_ptr11->set_ka(ka);
  matte_ptr11->set_kd(kd);
  matte_ptr11->set_cd(darkYellow);
  Sphere*	sphere_ptr11 = new Sphere(Point3D(-35, -37, -80), 22);
  sphere_ptr11->set_material(matte_ptr11);							// dark yellow
  add_object(sphere_ptr11);

  Matte* matte_ptr12 = new Matte;
  matte_ptr12->set_ka(ka);
  matte_ptr12->set_kd(kd);
  matte_ptr12->set_cd(darkYellow);
  Sphere*	sphere_ptr12 = new Sphere(Point3D(10, 43, -80), 22);
  sphere_ptr12->set_material(matte_ptr12);							// dark yellow
  add_object(sphere_ptr12);

  Matte* matte_ptr13 = new Matte;
  matte_ptr13->set_ka(ka);
  matte_ptr13->set_kd(kd);
  matte_ptr13->set_cd(darkYellow);
  Sphere*	sphere_ptr13 = new Sphere(Point3D(30, -7, -80), 10);
  sphere_ptr13->set_material(matte_ptr13);
  add_object(sphere_ptr13);											// dark yellow (hidden)

  Matte* matte_ptr14 = new Matte;
  matte_ptr14->set_ka(ka);
  matte_ptr14->set_kd(kd);
  matte_ptr14->set_cd(darkGreen);
  Sphere*	sphere_ptr14 = new Sphere(Point3D(-40, 48, -110), 18);
  sphere_ptr14->set_material(matte_ptr14); 							// dark green
  add_object(sphere_ptr14);

  Matte* matte_ptr15 = new Matte;
  matte_ptr15->set_ka(ka);
  matte_ptr15->set_kd(kd);
  matte_ptr15->set_cd(brown);
  Sphere*	sphere_ptr15 = new Sphere(Point3D(-10, 53, -120), 18);
  sphere_ptr15->set_material(matte_ptr15); 							// brown
  add_object(sphere_ptr15);

  Matte* matte_ptr16 = new Matte;
  matte_ptr16->set_ka(ka);
  matte_ptr16->set_kd(kd);
  matte_ptr16->set_cd(lightPurple);
  Sphere*	sphere_ptr16 = new Sphere(Point3D(-55, -52, -100), 10);
  sphere_ptr16->set_material(matte_ptr16);							// light purple
  add_object(sphere_ptr16);

  Matte* matte_ptr17 = new Matte;
  matte_ptr17->set_ka(ka);
  matte_ptr17->set_kd(kd);
  matte_ptr17->set_cd(brown);
  Sphere*	sphere_ptr17 = new Sphere(Point3D(5, -52, -100), 15);
  sphere_ptr17->set_material(matte_ptr17);							// browm
  add_object(sphere_ptr17);

  Matte* matte_ptr18 = new Matte;
  matte_ptr18->set_ka(ka);
  matte_ptr18->set_kd(kd);
  matte_ptr18->set_cd(darkPurple);
  Sphere*	sphere_ptr18 = new Sphere(Point3D(-20, -57, -120), 15);
  sphere_ptr18->set_material(matte_ptr18);							// dark purple
  add_object(sphere_ptr18);

  Matte* matte_ptr19 = new Matte;
  matte_ptr19->set_ka(ka);
  matte_ptr19->set_kd(kd);
  matte_ptr19->set_cd(darkGreen);
  Sphere*	sphere_ptr19 = new Sphere(Point3D(55, -27, -100), 17);
  sphere_ptr19->set_material(matte_ptr19);							// dark green
  add_object(sphere_ptr19);

  Matte* matte_ptr20 = new Matte;
  matte_ptr20->set_ka(ka);
  matte_ptr20->set_kd(kd);
  matte_ptr20->set_cd(brown);
  Sphere*	sphere_ptr20 = new Sphere(Point3D(50, -47, -120), 15);
  sphere_ptr20->set_material(matte_ptr20);							// browm
  add_object(sphere_ptr20);

  Matte* matte_ptr21 = new Matte;
  matte_ptr21->set_ka(ka);
  matte_ptr21->set_kd(kd);
  matte_ptr21->set_cd(lightPurple);
  Sphere*	sphere_ptr21 = new Sphere(Point3D(70, -42, -150), 10);
  sphere_ptr21->set_material(matte_ptr21);							// light purple
  add_object(sphere_ptr21);

  Matte* matte_ptr22 = new Matte;
  matte_ptr22->set_ka(ka);
  matte_ptr22->set_kd(kd);
  matte_ptr22->set_cd(lightPurple);
  Sphere*	sphere_ptr22 = new Sphere(Point3D(5, 73, -130), 12);
  sphere_ptr22->set_material(matte_ptr22);							// light purple
  add_object(sphere_ptr22);

  Matte* matte_ptr23 = new Matte;
  matte_ptr23->set_ka(ka);
  matte_ptr23->set_kd(kd);
  matte_ptr23->set_cd(darkPurple);
  Sphere*	sphere_ptr23 = new Sphere(Point3D(66, 21, -130), 13);
  sphere_ptr23->set_material(matte_ptr23);							// dark purple
  add_object(sphere_ptr23);

  Matte* matte_ptr24 = new Matte;
  matte_ptr24->set_ka(ka);
  matte_ptr24->set_kd(kd);
  matte_ptr24->set_cd(lightPurple);
  Sphere*	sphere_ptr24 = new Sphere(Point3D(72, -12, -140), 12);
  sphere_ptr24->set_material(matte_ptr24);							// light purple
  add_object(sphere_ptr24);

  Matte* matte_ptr25 = new Matte;
  matte_ptr25->set_ka(ka);
  matte_ptr25->set_kd(kd);
  matte_ptr25->set_cd(green);
  Sphere*	sphere_ptr25 = new Sphere(Point3D(64, 5, -160), 11);
  sphere_ptr25->set_material(matte_ptr25);					 		// green
  add_object(sphere_ptr25);

  Matte* matte_ptr26 = new Matte;
  matte_ptr26->set_ka(ka);
  matte_ptr26->set_kd(kd);
  matte_ptr26->set_cd(lightPurple);
  Sphere*	sphere_ptr26 = new Sphere(Point3D(55, 38, -160), 12);
  sphere_ptr26->set_material(matte_ptr26);							// light purple
  add_object(sphere_ptr26);

  Matte* matte_ptr27 = new Matte;
  matte_ptr27->set_ka(ka);
  matte_ptr27->set_kd(kd);
  matte_ptr27->set_cd(lightPurple);
  Sphere*	sphere_ptr27 = new Sphere(Point3D(-73, -2, -160), 12);
  sphere_ptr27->set_material(matte_ptr27);							// light purple
  add_object(sphere_ptr27);

  Matte* matte_ptr28 = new Matte;
  matte_ptr28->set_ka(ka);
  matte_ptr28->set_kd(kd);
  matte_ptr28->set_cd(darkPurple);
  Sphere*	sphere_ptr28 = new Sphere(Point3D(30, -62, -140), 15);
  sphere_ptr28->set_material(matte_ptr28); 							// dark purple
  add_object(sphere_ptr28);

  Matte* matte_ptr29 = new Matte;
  matte_ptr29->set_ka(ka);
  matte_ptr29->set_kd(kd);
  matte_ptr29->set_cd(darkPurple);
  Sphere*	sphere_ptr29 = new Sphere(Point3D(25, 63, -140), 15);
  sphere_ptr29->set_material(matte_ptr29);							// dark purple
  add_object(sphere_ptr29);

  Matte* matte_ptr30 = new Matte;
  matte_ptr30->set_ka(ka);
  matte_ptr30->set_kd(kd);
  matte_ptr30->set_cd(darkPurple);
  Sphere*	sphere_ptr30 = new Sphere(Point3D(-60, 46, -140), 15);
  sphere_ptr30->set_material(matte_ptr30); 							// dark purple
  add_object(sphere_ptr30);

  Matte* matte_ptr31 = new Matte;
  matte_ptr31->set_ka(ka);
  matte_ptr31->set_kd(kd);
  matte_ptr31->set_cd(lightPurple);
  Sphere*	sphere_ptr31 = new Sphere(Point3D(-30, 68, -130), 12);
  sphere_ptr31->set_material(matte_ptr31); 							// light purple
  add_object(sphere_ptr31);

  Matte* matte_ptr32 = new Matte;
  matte_ptr32->set_ka(ka);
  matte_ptr32->set_kd(kd);
  matte_ptr32->set_cd(green);
  Sphere*	sphere_ptr32 = new Sphere(Point3D(58, 56, -180), 11);
  sphere_ptr32->set_material(matte_ptr32);							//  green
  add_object(sphere_ptr32);

  Matte* matte_ptr33 = new Matte;
  matte_ptr33->set_ka(ka);
  matte_ptr33->set_kd(kd);
  matte_ptr33->set_cd(green);
  Sphere*	sphere_ptr33 = new Sphere(Point3D(-63, -39, -180), 11);
  sphere_ptr33->set_material(matte_ptr33);							// green
  add_object(sphere_ptr33);

  Matte* matte_ptr34 = new Matte;
  matte_ptr34->set_ka(ka);
  matte_ptr34->set_kd(kd);
  matte_ptr34->set_cd(lightPurple);
  Sphere*	sphere_ptr34 = new Sphere(Point3D(46, 68, -200), 10);
  sphere_ptr34->set_material(matte_ptr34);							// light purple
  add_object(sphere_ptr34);

  Matte* matte_ptr35 = new Matte;
  matte_ptr35->set_ka(ka);
  matte_ptr35->set_kd(kd);
  matte_ptr35->set_cd(lightPurple);
  Sphere*	sphere_ptr35 = new Sphere(Point3D(-3, -72, -130), 12);
  sphere_ptr35->set_material(matte_ptr35);							// light purple
  add_object(sphere_ptr35);

  // vertical plane

  Matte* matte_ptr36 = new Matte;
  matte_ptr36->set_ka(ka);
  matte_ptr36->set_kd(kd);
  matte_ptr36->set_cd(grey);
  Plane* plane_ptr = new Plane(Point3D(0, 0, -150), Normal(0, 0, 1));
  plane_ptr->set_material(matte_ptr36);
  add_object (plane_ptr);
#endif

}

