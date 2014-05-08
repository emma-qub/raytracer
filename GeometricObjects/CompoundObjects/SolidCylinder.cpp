#include "SolidCylinder.h"
#include "Maths.h"
#include "Material.h"

SolidCylinder::SolidCylinder(void):
  Compound() {

  add_object(new OpenCylinder);
  add_object(new Disk(Point3D(0.0, -1.0, 0.0), Normal(0.0, -1.0, 0.0), 1.0));
  add_object(new Disk(Point3D(0.0, 1.0, 0.0), Normal(0.0, 1.0, 0.0), 1.0));
}

SolidCylinder::SolidCylinder(const double bottom, const double top, const double radius):
  Compound() {

  add_object(new OpenCylinder(bottom, top, radius));
  add_object(new Disk(Point3D(0.0, bottom, 0.0), Normal(0.0, -1.0, 0.0), radius));
  add_object(new Disk(Point3D(0.0, top, 0.0), Normal(0.0, 1.0, 0.0), radius));
}

SolidCylinder::SolidCylinder(const SolidCylinder& sc):
  Compound(sc) {
}

SolidCylinder* SolidCylinder::clone (void) const {
  return new SolidCylinder(*this);
}

SolidCylinder& SolidCylinder::operator=(const SolidCylinder& rhs) {
  if (this == &rhs)
    return *this;

  Compound::operator= (rhs);

  return *this;
}

SolidCylinder::~SolidCylinder(void) {
}

bool SolidCylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  return Compound::hit(ray, tmin, sr);
}

bool SolidCylinder::shadow_hit(const Ray& ray, float& tmin) const {
  if (!shadows)
    return false;

  return Compound::shadow_hit(ray, tmin);
}
