#include "ThickRing.h"
#include "ConcavePartCylinder.h"
#include "ConvexPartCylinder.h"
#include "Maths.h"
#include "Material.h"

ThickRing::ThickRing(void):
  Compound() {

  add_object(new OpenCone);
  add_object(new Disk(Point3D(0.0, -1.0, 0.0), Normal(0.0, -1.0, 0.0), 1.0));
  add_object(new Disk(Point3D(0.0, 1.0, 0.0), Normal(0.0, 1.0, 0.0), 1.0));
}

ThickRing::ThickRing(const double bottom, const double top, const double r1, const double r2):
  Compound() {

  add_object(new ConcavePartCylinder(bottom, top, r1));
  add_object(new ConvexPartCylinder(bottom, top, r2));
  add_object(new Annulus(Point3D(0.0, bottom, 0.0), Normal(0.0, -1.0, 0.0), r1, r2));
  add_object(new Annulus(Point3D(0.0, top, 0.0), Normal(0.0, 1.0, 0.0), r1, r2));
}

ThickRing::ThickRing(const ThickRing& sc):
  Compound(sc) {
}

ThickRing* ThickRing::clone (void) const {
  return new ThickRing(*this);
}

ThickRing& ThickRing::operator=(const ThickRing& rhs) {
  if (this == &rhs)
    return (*this);

  Compound::operator= (rhs);

  return *this;
}

ThickRing::~ThickRing(void) {
}
