#include "Constants.h"
#include "ConcavePartCylinder.h"
#include "Material.h"
#include <math.h>

// ----------------------------------------------------------------  default constructor
// a default ConcavePartCylinder is a whole cylinder

ConcavePartCylinder::ConcavePartCylinder (void):
  GeometricObject(),
  y0(-1.0),
  y1(1.0),
  radius(1.0),
  phi_min(0.0),     // in radians
  phi_max(TWO_PI),  // in radians
  inv_radius(1.0)	{
}


// ---------------------------------------------------------------- constructor

ConcavePartCylinder::ConcavePartCylinder (const double bottom,
                                        const double top,
                                        const double radius,
                                        const double azimuth_min,	// in degrees
                                        const double azimuth_max):	// in degrees

  GeometricObject(),
  y0(bottom),
  y1(top),
  radius(radius),
  phi_min(azimuth_min * PI_ON_180),   // in radians
  phi_max(azimuth_max * PI_ON_180),   // in radians
  inv_radius(1.0 / radius) {
}


// ---------------------------------------------------------------- constructor

ConcavePartCylinder::ConcavePartCylinder(const double bottom, const double top, const double 	r):
  GeometricObject(),
  y0(bottom),
  y1(top),
  radius(r),
  phi_min(0.0),
  phi_max(TWO_PI),
  inv_radius(1.0 / radius){
}


// ---------------------------------------------------------------- clone

ConcavePartCylinder* ConcavePartCylinder::clone(void) const {
  return (new ConcavePartCylinder(*this));
}


// ---------------------------------------------------------------- copy constructor

ConcavePartCylinder::ConcavePartCylinder (const ConcavePartCylinder& ps):
  GeometricObject(ps),
  y0(ps.y0),
  y1(ps.y1),
  radius(ps.radius),
  phi_min(ps.phi_min),
  phi_max(ps.phi_max),
  inv_radius(ps.inv_radius) {
}



// ---------------------------------------------------------------- assignment operator

ConcavePartCylinder& ConcavePartCylinder::operator= (const ConcavePartCylinder& rhs) {
  if (this == &rhs)
    return *this;

  GeometricObject::operator=(rhs);

  y0 = rhs.y0;
  y1 = rhs.y1;
  radius = rhs.radius;
  phi_min = rhs.phi_min;
  phi_max = rhs.phi_max;
  inv_radius = rhs.inv_radius;

  return *this;
}


// ---------------------------------------------------------------- destructor

ConcavePartCylinder::~ConcavePartCylinder(void) {
  delete material_ptr;
}


// ------------------------------------------------------------------------------ hit

bool ConcavePartCylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  double t;
  double ox = ray.o.x;
  double oz = ray.o.z;
  double dx = ray.d.x;
  double dz = ray.d.z;

  double a = dx * dx + dz * dz;
  double b = 2.0 * (ox * dx + oz * dz);
  double c = ox * ox + oz * oz - radius * radius;
  double disc = b * b - 4.0 * a * c ;

  if (disc < 0.0)
    return false;
  else {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    t = (-b - e) / denom;    // smaller root

    if (t > kEpsilon) {
      Vector3D hit = ray.o + t * ray.d;

      double phi = atan2(hit.x, hit.z);
      if (phi < 0.0)
        phi += TWO_PI;

      if (y0 <= hit.y && hit.y <= y1 && phi_min <= phi && phi <= phi_max) {
        tmin = t;
        sr.normal = - Normal((ox + t * dx) * inv_radius, 0.0, (oz + t * dz) * inv_radius); // points inwards
        sr.local_hit_point = ray.o + tmin * ray.d;
        return true;
      }
    }

    t = (-b + e) / denom;    // larger root

    if (t > kEpsilon) {
      Vector3D hit = ray.o + t * ray.d;

      double phi = atan2(hit.x, hit.z);
      if (phi < 0.0)
        phi += TWO_PI;

      if (y0 <= hit.y && hit.y <= y1 && phi_min <= phi && phi <= phi_max) {
        tmin = t;
        sr.normal = - Normal((ox + t * dx) * inv_radius, 0.0, (oz + t * dz) * inv_radius); // points inwards
        sr.local_hit_point = ray.o + tmin * ray.d;
        return true;
      }
    }
  }

  return false;
}

bool ConcavePartCylinder::shadow_hit(const Ray& ray, float& tmin) const {
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
  double disc = b * b - 4.0 * a * c ;


  if (disc < 0.0)
    return false;
  else {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    t = (-b - e) / denom;    // smaller root

    if (t > kEpsilon) {
      double yhit = oy + t * dy;

      if (yhit > y0 && yhit < y1) {
        tmin = t;
        return true;
      }
    }

    t = (-b + e) / denom;    // larger root

    if (t > kEpsilon) {
      double yhit = oy + t * dy;

      if (yhit > y0 && yhit < y1) {
        tmin = t;
        return true;
      }
    }
  }

  return false;
}
