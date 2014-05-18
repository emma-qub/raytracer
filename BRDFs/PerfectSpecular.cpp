#include "PerfectSpecular.h"
#include "Constants.h"

// ---------------------------------------------------------------------- default constructor

PerfectSpecular::PerfectSpecular(void):
  BRDF(),
  kr(0.0),
  cr(1.0) {
}


// ---------------------------------------------------------------------- copy constructor

PerfectSpecular::PerfectSpecular(const PerfectSpecular& ps):
  BRDF(ps),
  kr(ps.kr),
  cr(ps.cr) {
}


// ---------------------------------------------------------------------- clone

PerfectSpecular* PerfectSpecular::clone(void) const {
  return new PerfectSpecular(*this);
}


// ---------------------------------------------------------------------- destructor

PerfectSpecular::~PerfectSpecular(void) {
}


// ---------------------------------------------------------------------- assignment operator

PerfectSpecular& PerfectSpecular::operator= (const PerfectSpecular& rhs) {
  if (this == &rhs)
    return *this;

  BRDF::operator= (rhs);

  kr = rhs.kr;
  cr = rhs.cr;

  return *this;
}

RGBColor PerfectSpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const {
  float ndotwo = sr.normal * wo;
  wi = -wo + 2.0 * sr.normal * ndotwo;

  return kr * cr / (sr.normal * wi);
}
