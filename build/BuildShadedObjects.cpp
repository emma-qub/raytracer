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
#include "Plane.h"
#include "Pinhole.h"
#include "ThinLens.h"
#include "StereoCamera.h"
#include "Fisheye.h"
#include "Maths.h"

#define perso 1
#define sphere 0
#define cylinder 0
#define torus 0
#define disk 0
#define rectangle 0
#define annulus 0
#define cone 0
#define convexpartsphere 0
#define concavepartsphere 0
#define openpartsphere 0
#define convexpartcylinder 0
#define concavepartcylinder 0
#define openpartcylinder 0
#define convexparttorus 0
#define concaveparttorus 0
#define openparttorus 0
#define partannulus 0
#define genericsphere 0
#define compoundobject 0
#define bowlthickobject 0
#define bowlroundedobject 0
#define solidcylinder 0
#define solidcone 0
#define thickring 0
#define convexcylinder 0
#define concavecylinder 0
#define instance 0
#define thinlenscamera 0
#define stereocamera 0
#define beveledbox 0
#define beveledwedge 0
#define chocolate 0
#define fisheye 1

#include <iostream>

void World::build(void) {
  int num_samples = 100;

  // view plane

  vp.set_hres(400);
  vp.set_vres(400);
  vp.set_pixel_size(0.5);
  vp.set_samples(num_samples);

  // the ambient light here is the same as the default set in the World
  // constructor, and can therefore be left out

  Ambient* ambient_ptr = new Ambient;
  ambient_ptr->scale_radiance(1.0);
  set_ambient_light(ambient_ptr);

  background_color = black;			// default color - this can be left out

  tracer_ptr = new RayCast(this);


  // camera

  Pinhole* pinhole_ptr = new Pinhole;
  pinhole_ptr->set_eye(0, 0, 500);
  pinhole_ptr->set_lookat(0.0);
  pinhole_ptr->set_view_distance(600.0);
  pinhole_ptr->compute_uvw();
  set_camera(pinhole_ptr);


  // light

//  Directional* light_ptr1 = new Directional;
//  light_ptr1->set_direction(100, 100, 200);
//  light_ptr1->scale_radiance(3.0);
//  add_light(light_ptr1);


  // colors

  RGBColor yellow(1, 1, 0);										// yellow
  RGBColor brown(0.71, 0.40, 0.16);								// brown
  RGBColor darkGreen(0.0, 0.41, 0.41);							// darkGreen
  RGBColor orange(1, 0.75, 0);									// orange
  RGBColor green(0, 0.6, 0.3);									// green
  RGBColor lightGreen(0.65, 1, 0.30);								// light green
  RGBColor darkYellow(0.61, 0.61, 0);								// dark yellow
  RGBColor lightPurple(0.65, 0.3, 1);								// light purple
  RGBColor darkPurple(0.5, 0, 1);									// dark purple
  RGBColor grey(0.25);											// grey


  // Matte material reflection coefficients - common to all materials

  float ka = 0.25;
  float kd = 0.75;

#if perso
  // camera
  pinhole_ptr->set_eye(300, 200, 500);
  pinhole_ptr->set_lookat(0.0);
  pinhole_ptr->set_view_distance(600.0);
  pinhole_ptr->compute_uvw();

# if sphere
  Matte* matte_ptr = new Matte;
  matte_ptr->set_ka(ka);
  matte_ptr->set_kd(kd);
  matte_ptr->set_cd(yellow);
  Sphere* sphere_ptr = new Sphere(Point3D(), 50);
  sphere_ptr->set_material(matte_ptr);	   							// yellow
  add_object(sphere_ptr);
# endif

# if cylinder
  Matte* matte_ptr = new Matte;
  matte_ptr->set_ka(ka);
  matte_ptr->set_kd(kd);
  matte_ptr->set_cd(yellow);
  OpenCylinder* cylinder_ptr = new OpenCylinder(-5, 50, 30);
  cylinder_ptr->set_material(matte_ptr);	   							// yellow
  add_object(cylinder_ptr);
# endif

#if torus
  Matte* matte_ptr5 = new Matte;
  matte_ptr5->set_ka(ka);
  matte_ptr5->set_kd(kd);
  matte_ptr5->set_cd(yellow);
  Torus* torus_ptr = new Torus(60, 20);
  torus_ptr->set_material(matte_ptr5);								// yellow
  add_object(torus_ptr);
# endif

#if disk
  Matte* matte_ptr5 = new Matte;
  matte_ptr5->set_ka(ka);
  matte_ptr5->set_kd(kd);
  matte_ptr5->set_cd(yellow);
  Disk* disk_ptr = new Disk(Point3D(), Normal(0.0, 1.0, 1.0), 50.0);
  disk_ptr->set_material(matte_ptr5);								// yellow
  add_object(disk_ptr);
# endif

#if rectangle
  Matte* matte_ptr15 = new Matte;
  matte_ptr15->set_ka(ka);
  matte_ptr15->set_kd(kd);
  matte_ptr15->set_cd(yellow);
  Rectangle*	rectangle_ptr15 =
    new Rectangle(Point3D(-40, 0, -20), Vector3D(70, 0, 0), Vector3D(0, 50, 0));
  rectangle_ptr15->set_material(matte_ptr15); 							// yellow
  add_object(rectangle_ptr15);
# endif

#if annulus
  Matte* matte_ptr4 = new Matte;
  matte_ptr4->set_ka(ka);
  matte_ptr4->set_kd(kd);
  matte_ptr4->set_cd(yellow);
  Annulus* annulus_ptr = new Annulus(Point3D(0, 0, 0), Normal(0, 1, 0), 50, 60);
  annulus_ptr->set_material(matte_ptr4);								// yellow
  add_object(annulus_ptr);
# endif

#if cone
  Matte* matte_ptr = new Matte;
  matte_ptr->set_ka(ka);
  matte_ptr->set_kd(kd);
  matte_ptr->set_cd(yellow);
  OpenCone* cone_ptr = new OpenCone(50, 30);
  cone_ptr->set_material(matte_ptr);	   							// yellow
  add_object(cone_ptr);
# endif

# if convexpartsphere
  Matte* matte_ptr101 = new Matte;
  matte_ptr101->set_ka(ka);
  matte_ptr101->set_kd(kd);
  matte_ptr101->set_cd(yellow);
  ConvexPartSphere* convexPartSphere =
    new ConvexPartSphere(Point3D(0, 0, 0), 50, 45, 325, 45, 135);
  convexPartSphere->set_material(matte_ptr101);	   							// yellow
  add_object(convexPartSphere);
# endif

# if concavepartsphere
  Matte* matte_ptr101 = new Matte;
  matte_ptr101->set_ka(ka);
  matte_ptr101->set_kd(kd);
  matte_ptr101->set_cd(yellow);
  ConcavePartSphere* concavePartSphere =
    new ConcavePartSphere(Point3D(0, 0, 0), 50, 45, 325, 45, 135);
  concavePartSphere->set_material(matte_ptr101);	   							// yellow
  add_object(concavePartSphere);
# endif

# if openpartsphere
  Matte* matte_ptr102 = new Matte;
  matte_ptr102->set_ka(ka);
  matte_ptr102->set_kd(kd);
  matte_ptr102->set_cd(yellow);
  OpenPartSphere* openPartSphere =
    new OpenPartSphere(Point3D(0, 0, 0), 50, 45, 325, 45, 135);
  openPartSphere->set_material(matte_ptr102);	   							// yellow
  add_object(openPartSphere);
# endif

# if convexpartcylinder
  Matte* matte_ptr103 = new Matte;
  matte_ptr103->set_ka(ka);
  matte_ptr103->set_kd(kd);
  matte_ptr103->set_cd(yellow);
  ConvexPartCylinder* convexPartCylinder =
    new ConvexPartCylinder(-25, 25, 50, 45, 325);
  convexPartCylinder->set_material(matte_ptr103);	   							// yellow
  add_object(convexPartCylinder);
# endif

# if concavepartcylinder
  Matte* matte_ptr104 = new Matte;
  matte_ptr104->set_ka(ka);
  matte_ptr104->set_kd(kd);
  matte_ptr104->set_cd(yellow);
  ConcavePartCylinder* concavePartCylinder =
    new ConcavePartCylinder(-25, 25, 50, 45, 325);
  concavePartCylinder->set_material(matte_ptr104);	   							// yellow
  add_object(concavePartCylinder);
# endif

# if openpartcylinder
  Matte* matte_ptr105 = new Matte;
  matte_ptr105->set_ka(ka);
  matte_ptr105->set_kd(kd);
  matte_ptr105->set_cd(yellow);
  OpenPartCylinder* openPartCylinder =
    new OpenPartCylinder(-25, 25, 50, 45, 325);
  openPartCylinder->set_material(matte_ptr105);	   							// yellow
  add_object(openPartCylinder);
# endif

# if convexparttorus
  Matte* matte_ptr106 = new Matte;
  matte_ptr106->set_ka(ka);
  matte_ptr106->set_kd(kd);
  matte_ptr106->set_cd(yellow);
  ConvexPartTorus* convexPartTorus =
    new ConvexPartTorus(60, 20, 45, 325, 90, 360);
  convexPartTorus->set_material(matte_ptr106);	   							// yellow
  add_object(convexPartTorus);
# endif

# if concaveparttorus
  Matte* matte_ptr107 = new Matte;
  matte_ptr107->set_ka(ka);
  matte_ptr107->set_kd(kd);
  matte_ptr107->set_cd(yellow);
  ConcavePartTorus* concavePartTorus =
    new ConcavePartTorus(60, 20, 45, 325, 90, 360);
  concavePartTorus->set_material(matte_ptr107);	   							// yellow
  add_object(concavePartTorus);
# endif

# if openparttorus
  Matte* matte_ptr108 = new Matte;
  matte_ptr108->set_ka(ka);
  matte_ptr108->set_kd(kd);
  matte_ptr108->set_cd(yellow);
  OpenPartTorus* openPartTorus =
    new OpenPartTorus(60, 20, 45, 325, 90, 360);
  openPartTorus->set_material(matte_ptr108);	   							// yellow
  add_object(openPartTorus);
# endif

# if partannulus
  Matte* matte_ptr109 = new Matte;
  matte_ptr109->set_ka(ka);
  matte_ptr109->set_kd(kd);
  matte_ptr109->set_cd(yellow);
  PartAnnulus* partAnnulus = new PartAnnulus(0, 50, 60, 45, 325);
  partAnnulus->set_material(matte_ptr109);	   							// yellow
  add_object(partAnnulus);
# endif

# if genericsphere
  // camera
  pinhole_ptr->set_eye(0, 0, 10);
  pinhole_ptr->set_lookat(0.0);
  pinhole_ptr->set_view_distance(600.0);
  pinhole_ptr->compute_uvw();
  // generic sphere
  Matte* matte_ptr111 = new Matte;
  matte_ptr111->set_ka(ka);
  matte_ptr111->set_kd(kd);
  matte_ptr111->set_cd(yellow);
  GenericSphere* genericSphere = new GenericSphere;
  genericSphere->set_material(matte_ptr111);	   							// yellow
  add_object(genericSphere);
# endif

# if compoundobject
  Matte* matte_ptr112 = new Matte;
  matte_ptr112->set_ka(ka);
  matte_ptr112->set_kd(kd);
  matte_ptr112->set_cd(yellow);
  Compound* compound = new Compound;
  compound->set_material(matte_ptr112);	   							// yellow
  add_object(compound);
# endif

# if bowlthickobject
  Matte* matte_ptr113 = new Matte;
  matte_ptr113->set_ka(ka);
  matte_ptr113->set_kd(kd);
  matte_ptr113->set_cd(yellow);
  ConcavePartSphere* bowl_interior =
    new ConcavePartSphere(Point3D(), 50, 0, 360, 90, 180);
  bowl_interior->set_material(matte_ptr113);	   							// yellow
  add_object(bowl_interior);
  ConvexPartSphere* bowl_exterior =
    new ConvexPartSphere(Point3D(), 60, 0, 360, 90, 180);
  bowl_exterior->set_material(matte_ptr113->clone());	   							// yellow
  add_object(bowl_exterior);
  Annulus* edge = new Annulus(Point3D(), Normal(0.0, 1.0, 0.0), 50, 60);
  edge->set_material(matte_ptr113->clone());	   							// yellow
  add_object(edge);
# endif

# if bowlroundedobject
  Matte* matte_ptr114 = new Matte;
  matte_ptr114->set_ka(ka);
  matte_ptr114->set_kd(kd);
  matte_ptr114->set_cd(yellow);
  ConcavePartSphere* bowl_interior =
    new ConcavePartSphere(Point3D(), 50, 0, 360, 90, 180);
  ConvexPartSphere* bowl_exterior =
    new ConvexPartSphere(Point3D(), 60, 0, 360, 90, 180);
  Torus* edge = new Torus(55, 5);
  Compound* compound = new Compound;
  compound->add_object(bowl_interior);
  compound->add_object(bowl_exterior);
  compound->add_object(edge);
  compound->set_material(matte_ptr114);
  add_object(compound);
# endif

# if solidcylinder
  Matte* matte_ptr115 = new Matte;
  matte_ptr115->set_ka(ka);
  matte_ptr115->set_kd(kd);
  matte_ptr115->set_cd(yellow);
  SolidCylinder* solidCylinder = new SolidCylinder(-5, 50, 30);
  solidCylinder->set_material(matte_ptr115);	   							// yellow
  add_object(solidCylinder);
# endif

# if solidcone
  Matte* matte_ptr116 = new Matte;
  matte_ptr116->set_ka(ka);
  matte_ptr116->set_kd(kd);
  matte_ptr116->set_cd(yellow);
  SolidCone* solidCone = new SolidCone(50, 30);
  solidCone->set_material(matte_ptr116);	   							// yellow
  add_object(solidCone);
# endif

# if thickring
  Matte* matte_ptr116 = new Matte;
  matte_ptr116->set_ka(ka);
  matte_ptr116->set_kd(kd);
  matte_ptr116->set_cd(yellow);
  ThickRing* thickRing = new ThickRing(-10, 20, 40, 50);
  thickRing->set_material(matte_ptr116);	   							// yellow
  add_object(thickRing);
# endif

# if convexcylinder
  Matte* matte_ptr117 = new Matte;
  matte_ptr117->set_ka(ka);
  matte_ptr117->set_kd(kd);
  matte_ptr117->set_cd(yellow);
  ConvexCylinder* convexCylinder = new ConvexCylinder(-5, 50, 30);
  convexCylinder->set_material(matte_ptr117);	   							// yellow
  add_object(convexCylinder);
# endif

# if concavecylinder
  Matte* matte_ptr118 = new Matte;
  matte_ptr118->set_ka(ka);
  matte_ptr118->set_kd(kd);
  matte_ptr118->set_cd(yellow);
  ConcaveCylinder* concaveCylinder = new ConcaveCylinder(-5, 50, 30);
  concaveCylinder->set_material(matte_ptr118);	   							// yellow
  add_object(concaveCylinder);
# endif

# if instance
  pinhole_ptr->set_eye(300, 200, 300);
  pinhole_ptr->set_lookat(0.0);
  pinhole_ptr->set_view_distance(600.0);
  pinhole_ptr->compute_uvw();
  set_camera(pinhole_ptr);

  GenericSphere* solidCylinder = new GenericSphere;
  for (int i = -40; i <= 40; i += 20) {
    for (int j = -40; j <= 40; j += 20) {

      Matte* matte = new Matte;
      matte->set_ka(ka);
      matte->set_kd(kd);
      matte->set_cd(RGBColor(rand_float(), rand_float(), rand_float()));

      Instance* instance_ptr = new Instance(solidCylinder);
      float h = rand_float(5.0, 20.0);
      instance_ptr->scale(7.0, h, 7.0);
      instance_ptr->translate(i, 0.0, j);
      instance_ptr->set_material(matte);
      add_object(instance_ptr);
    }
  }
# endif

# if thinlenscamera
  num_samples = 100;
  vp.set_hres(400);
  vp.set_vres(300);
  vp.set_pixel_size(0.05);
  vp.set_sampler(new MultiJittered(num_samples));

  tracer_ptr = new RayCast(this);
  background_color = white;

  ambient_ptr->scale_radiance(0.5);

  ThinLens* thin_lens_ptr = new ThinLens;
  thin_lens_ptr->set_sampler(new MultiJittered(num_samples));
  thin_lens_ptr->set_eye(0, 6, 50);
  thin_lens_ptr->set_lookat(0, 6, 0);
  thin_lens_ptr->set_view_distance(40.0);
  thin_lens_ptr->set_focal_distance(190.0);
  thin_lens_ptr->set_lens_radius(1.0);
  thin_lens_ptr->compute_uvw();
  set_camera(thin_lens_ptr);

  // Yellow rectangle
  Matte* matte_ptr_1 = new Matte;
  matte_ptr_1->set_ka(ka);
  matte_ptr_1->set_kd(kd);
  matte_ptr_1->set_cd(yellow);
  Rectangle* rectangle_ptr1 =
    new Rectangle(Point3D(-15, 0, -40), Vector3D(12, 0, 0), Vector3D(0, 20, 0));
  rectangle_ptr1->set_material(matte_ptr_1); 							// yellow
  add_object(rectangle_ptr1);

  // Green rectangle
  Matte* matte_ptr_2 = new Matte;
  matte_ptr_2->set_ka(ka);
  matte_ptr_2->set_kd(kd);
  matte_ptr_2->set_cd(green);
  Rectangle* rectangle_ptr2 =
    new Rectangle(Point3D(-2, 0, -90), Vector3D(12, 0, 0), Vector3D(0, 20, 0));
  rectangle_ptr2->set_material(matte_ptr_2); 							// green
  add_object(rectangle_ptr2);

  // Orange rectangle
  Matte* matte_ptr_3 = new Matte;
  matte_ptr_3->set_ka(ka);
  matte_ptr_3->set_kd(kd);
  matte_ptr_3->set_cd(orange);
  Rectangle* rectangle_ptr3 =
    new Rectangle(Point3D(15, 0, -140), Vector3D(12, 0, 0), Vector3D(0, 20, 0));
  rectangle_ptr3->set_material(matte_ptr_3); 							// orange
  add_object(rectangle_ptr3);
# endif

#if stereocamera
  num_samples = 100;
  vp.set_hres(200);
  vp.set_vres(150);
  vp.set_pixel_size(0.05);
  vp.set_sampler(new MultiJittered(num_samples));


  Matte* matte_ptr = new Matte;
  matte_ptr->set_ka(ka);
  matte_ptr->set_kd(kd);
  matte_ptr->set_cd(yellow);
  OpenPartTorus* openPartTorus =
    new OpenPartTorus(3, 1, 45, 325, 90, 360);
  openPartTorus->set_material(matte_ptr);	   							// yellow
  add_object(openPartTorus);

  float vpd = 100;        // view-plane distance

  Pinhole* left_camera_ptr = new Pinhole;
  left_camera_ptr->set_view_distance(vpd);

  Pinhole* right_camera_ptr = new Pinhole;
  right_camera_ptr->set_view_distance(vpd);

  StereoCamera* stereo_ptr = new StereoCamera;
  stereo_ptr->set_left_camera(left_camera_ptr);
  stereo_ptr->set_right_camera(right_camera_ptr);
  //stereo_ptr->use_parallel_viewing();
  stereo_ptr->use_transverse_viewing();
  stereo_ptr->set_pixel_gap(5);       // in pixels
  stereo_ptr->set_eye(5, 50, 100);
  stereo_ptr->set_lookat(0);
  stereo_ptr->compute_uvw();
  stereo_ptr->set_stereo_angle(0.75); // in degrees
  stereo_ptr->setup_cameras();
  set_camera(stereo_ptr);
# endif

# if beveledbox
  Matte* matte_ptr = new Matte;
  matte_ptr->set_ka(ka);
  matte_ptr->set_kd(kd);
  matte_ptr->set_cd(green);
  BeveledBox* beveledBox =
    new BeveledBox(Point3D(-50, -5, -40), Point3D(50, 5, 40), 2);
  beveledBox->set_material(matte_ptr);	   							// green
  add_object(beveledBox);
# endif

# if beveledwedge
  Matte* matte_ptr = new Matte;
  matte_ptr->set_ka(ka);
  matte_ptr->set_kd(kd);
  matte_ptr->set_cd(green);
  BeveledWedge* beveledWedge =
    new BeveledWedge(-10, 10, 20, 60, 2, 45, 325);
  beveledWedge->set_material(matte_ptr);	   							// green
  add_object(beveledWedge);
# endif

# if chocolate
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
# endif

# ifdef fisheye
  num_samples = 16;

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
# endif

#else

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

#endif

  // vertical plane

//  Matte* matte_ptr36 = new Matte;
//  matte_ptr36->set_ka(ka);
//  matte_ptr36->set_kd(kd);
//  matte_ptr36->set_cd(grey);
//  Plane* plane_ptr = new Plane(Point3D(0, 0, -150), Normal(0, 0, 1));
//  plane_ptr->set_material(matte_ptr36);
//  add_object (plane_ptr);
}

