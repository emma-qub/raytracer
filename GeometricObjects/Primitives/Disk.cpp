#include "Disk.h"
#include "Constants.h"
#include "Material.h"

Disk::Disk(void):
  GeometricObject(),
  center(0.0, 0.0, 0.0),
  normal(0.0, 1.0, 0.0),
  radius(1.0),
  r_squared(1.0) {
}

Disk::Disk(const Point3D& c, const Normal& n, double r):
  GeometricObject(),
  center(c),
  normal(n),
  radius(r),
  r_squared(radius * radius) {

  normal.normalize();
}

Disk::Disk(const Disk& disk):
  GeometricObject(disk),
  center(disk.center),
  normal(disk.normal),
  radius(disk.radius),
  r_squared(disk.r_squared) {
}

Disk* Disk::clone(void) const {
  return new Disk(*this);
}

Disk& Disk::operator=(const Disk& rhs) {
  if (this == &rhs)
    return *this;

  GeometricObject::operator=(rhs);

  center = rhs.center;
  normal = rhs.normal;
  radius = rhs.radius;
  r_squared = rhs.r_squared;

  return *this;
}

Disk::~Disk(void) {
  delete material_ptr;
}

bool Disk::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  float t = (center - ray.o) * normal / (ray.d * normal);

  if (t <= kEpsilon)
    return false;

  Point3D p = ray.o + t * ray.d;

  if (p.d_squared(center) < r_squared) {
    tmin = t;
    sr.normal = normal;
    sr.local_hit_point = p;

    return true;
  }

  return false;
}

bool Disk::shadow_hit(const Ray& ray, float& tmin) const {
  float t = (center - ray.o) * normal / (ray.d * normal);

  if (t <= kEpsilon)
    return false;

  Point3D p = ray.o + t * ray.d;

  if (p.d_squared(center) < r_squared) {
    tmin = t;
    return true;
  }

  return false;
}
