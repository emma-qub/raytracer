#include "Cylinder.h"
#include "math.h"

const double Cylinder::kEpsilon = 0.001;

Cylinder::Cylinder(void):
  GeometricObject(),
  radius(1.0),
  top(1.0),
  bottom(-1.0),
  inv_radius(1.0) {
}

Cylinder::Cylinder(double r, double t, double b):
  GeometricObject(),
  radius(r),
  top(t),
  bottom(b),
  inv_radius(1.0 / radius) {
}

Cylinder::Cylinder(const Cylinder& cylinder):
  GeometricObject(cylinder),
  radius(cylinder.radius),
  top(cylinder.top),
  bottom(cylinder.bottom),
  inv_radius(cylinder.inv_radius) {
}

Cylinder* Cylinder::clone(void) const {
  return new Cylinder(*this);
}

Cylinder::~Cylinder(void) {
}

Cylinder& Cylinder::operator=(const Cylinder& cylinder) {
  if (this == &cylinder)
    return *this;

  GeometricObject::operator=(cylinder);

  radius = cylinder.radius;
  top = cylinder.top;
  bottom = cylinder.bottom;
  inv_radius = cylinder.inv_radius;

  return *this;
}

bool Cylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  double t;
  double ox = ray.o.x;
  double oy = ray.o.y;
  double oz = ray.o.z;
  double dx = ray.d.x;
  double dy = ray.d.y;
  double dz = ray.d.z;

  double a = dx * dx + dz * dz;
  double b = 2.0 * (ox * dx + oz * dz);
  double c = ox * ox + oz * oz - radius * radius;
  double disc = b * b - 4.0 * a * c;

  if (disc < 0.0)
    return false;
  else {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    t = (-b - e) / denom;   // smaller root

    if (t > kEpsilon) {
      double yhit = oy + t * dy;

      if (bottom < yhit && yhit < top) {
        tmin = t;
        sr.normal = Normal((ox + t * dx) * inv_radius, 0.0, (oz + t * dz) * inv_radius);

        // test for hitting from inside
        if (-ray.d * sr.normal < 0.0)
          sr.normal = -sr.normal;

        sr.local_hit_point = ray.o + tmin * ray.d;

        return true;
      }
    }

    t = (-b + e) / denom;   // larger root

    if (t > kEpsilon) {
      double yhit = oy + t * dy;

      if (bottom < yhit && yhit < top) {
        tmin = t;
        sr.normal = Normal((ox + t * dx) * inv_radius, 0.0, (oz + t * dz) * inv_radius);

        // test for hitting inside surface
        if (-ray.d * sr.normal < 0.0)
          sr.normal = -sr.normal;

        sr.local_hit_point = ray.o + tmin * ray.d;

        return true;
      }
    }
  }

  return false;
}
