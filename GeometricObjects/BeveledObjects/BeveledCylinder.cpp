// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This file contains the definition of the class BeveledCylinder

#include "BeveledCylinder.h"
#include "OpenCylinder.h"
#include "Torus.h"
#include "Disk.h"
#include "Instance.h"

#include "Vector3D.h"
#include "Normal.h"

BeveledCylinder::BeveledCylinder(void):
  Compound(),
  y0(-1.0),
  y1(1.0),
  r(1.0),
  rb(0.1),
  bbox(Point3D(y0), Point3D(y1)) {

  // bottom
  objects.push_back(new Disk(Point3D(0.0, y0, 0.0), Normal(0.0, -1.0, 0.0), r - 2 * rb));

  // bottom beveled
  Instance* bottom_torus = new Instance(new Torus(r - rb, rb));
  bottom_torus->translate(0.0, y0 + rb, 0.0);
  bottom_torus->transform_texture(false);
  objects.push_back(bottom_torus);

  // wall
  objects.push_back(new OpenCylinder(y0 + rb, y1 - rb, r));

  // top beveled
  Instance* top_torus = new Instance(new Torus(r - rb, rb));
  top_torus->translate(0.0, y1 - rb, 0.0);
  top_torus->transform_texture(false);
  objects.push_back(top_torus);

  // top
  objects.push_back(new Disk(Point3D(0.0, y1, 0.0), Normal(0.0, 1.0, 0.0), r - 2 * rb));
}

BeveledCylinder::BeveledCylinder(const double bottom, const double top, const double radius, const double bevel_radius):
  Compound(),
  y0(bottom),
  y1(top),
  r(radius),
  rb(bevel_radius),
  bbox(Point3D(y0), Point3D(y1)) {

  // bottom
  objects.push_back(new Disk(Point3D(0.0, y0, 0.0), Normal(0.0, -1.0, 0.0), r - 2 * rb));

  // bottom beveled
  Instance* bottom_torus = new Instance(new Torus(r - rb, rb));
  bottom_torus->translate(0.0, y0 + rb, 0.0);
  bottom_torus->transform_texture(false);
  objects.push_back(bottom_torus);

  // wall
  objects.push_back(new OpenCylinder(y0 + rb, y1 - rb, r));

  // top beveled
  Instance* top_torus = new Instance(new Torus(r - rb, rb));
  top_torus->translate(0.0, y1 - rb, 0.0);
  top_torus->transform_texture(false);
  objects.push_back(top_torus);

  // top
  objects.push_back(new Disk(Point3D(0.0, y1, 0.0), Normal(0.0, 1.0, 0.0), r - 2 * rb));
}

BeveledCylinder::BeveledCylinder(const BeveledCylinder& bc):
  Compound(bc),
  y0(bc.y0),
  y1(bc.y1),
  r(bc.r),
  rb(bc.rb),
  bbox(bc.bbox) {
}

BeveledCylinder* BeveledCylinder::clone(void) const {
  return new BeveledCylinder(*this);
}

BeveledCylinder& BeveledCylinder::operator= (const BeveledCylinder& rhs)
{
  if (this == &rhs)
    return (*this);

  Compound::operator=(rhs);

  y0		= rhs.y0;
  y1		= rhs.y1;
  r     = rhs.r;
  rb		= rhs.rb;
  bbox	= rhs.bbox;

  return *this;
}

BeveledCylinder::~BeveledCylinder (void) {
}

BBox BeveledCylinder::get_bounding_box(void) {
  return bbox;
}

//bool
//BeveledCylinder::shadow_hit(const Ray& ray, double& tmin) const {
//  if (bbox.hit(ray))
//    return (Compound::shadow_hit(ray, tmin));
//  else
//    return (false);
//}

bool
BeveledCylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  if (bbox.hit(ray))
    return Compound::hit(ray, tmin, sr);
  else
    return false;
}
