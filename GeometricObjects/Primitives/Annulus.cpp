#include "Annulus.h"
#include "Constants.h"
#include "Material.h"

Annulus::Annulus(void):
  GeometricObject(),
  center(0.0, 0.0, 0.0),
  normal(0.0, 1.0, 0.0),
  inner_radius(0.8),
  outer_radius(1.0),
  i_r_squared(0.64),
  o_r_squared(1.0) {
}

Annulus::Annulus(const Point3D& c, const Normal& n, double i_r, double o_r):
  GeometricObject(),
  center(c),
  normal(n),
  inner_radius(i_r),
  outer_radius(o_r),
  i_r_squared(inner_radius * inner_radius),
  o_r_squared(outer_radius * outer_radius) {

  normal.normalize();
}

Annulus::Annulus(const Annulus& annulus):
  GeometricObject(annulus),
  center(annulus.center),
  normal(annulus.normal),
  inner_radius(annulus.inner_radius),
  outer_radius(annulus.outer_radius),
  i_r_squared(annulus.i_r_squared),
  o_r_squared(annulus.o_r_squared) {
}

Annulus* Annulus::clone(void) const {
  return new Annulus(*this);
}

Annulus& Annulus::operator=(const Annulus& rhs) {
  if (this == &rhs)
    return *this;

  GeometricObject::operator=(rhs);

  center = rhs.center;
  normal = rhs.normal;
  inner_radius = rhs.inner_radius;
  outer_radius = rhs.outer_radius;
  i_r_squared = rhs.i_r_squared;
  o_r_squared = rhs.o_r_squared;

  return *this;
}

Annulus::~Annulus(void) {
  delete material_ptr;
}

bool Annulus::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  float t = (center - ray.o) * normal / (ray.d * normal);

  if (t <= kEpsilon)
    return false;

  Point3D p = ray.o + t * ray.d;

  if (i_r_squared < p.d_squared(center) && p.d_squared(center) < o_r_squared) {
    tmin = t;
    sr.normal = normal;
    sr.local_hit_point = p;

    return true;
  }

  return false;
}

bool Annulus::shadow_hit(const Ray& ray, float& tmin) const {
  float t = (center - ray.o) * normal / (ray.d * normal);

  if (t <= kEpsilon)
    return false;

  Point3D p = ray.o + t * ray.d;

  if (i_r_squared < p.d_squared(center) && p.d_squared(center) < o_r_squared) {
    tmin = t;
    return true;
  }

  return false;
}
