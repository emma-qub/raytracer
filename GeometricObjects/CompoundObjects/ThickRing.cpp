#include "ThickRing.h"
#include "ConvexCylinder.h"
#include "ConcaveCylinder.h"
#include "Maths.h"
#include "Material.h"

ThickRing::ThickRing(void):
  Compound() {

  objects.push_back(new ConcaveCylinder(-1.0, 1.0, 0.5));
  add_object(new ConvexCylinder);
  add_object(new Disk(Point3D(0.0, -1.0, 0.0), Normal(0.0, -1.0, 0.0), 1.0));
  add_object(new Disk(Point3D(0.0, 1.0, 0.0), Normal(0.0, 1.0, 0.0), 1.0));
}

ThickRing::ThickRing(const double bottom, const double top, const double r1, const double r2):
  Compound() {

  add_object(new ConcaveCylinder(bottom, top, r1));
  add_object(new ConvexCylinder(bottom, top, r2));
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
    return *this;

  Compound::operator= (rhs);

  return *this;
}

ThickRing::~ThickRing(void) {
}

bool ThickRing::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  return Compound::hit(ray, tmin, sr);
}

bool ThickRing::shadow_hit(const Ray& ray, float& tmin) const {
  if (!shadows)
    return false;

  return Compound::shadow_hit(ray, tmin);
}
