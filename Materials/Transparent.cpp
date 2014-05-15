#include "Transparent.h"

#include <cmath>

// ---------------------------------------------------------------- default constructor

Transparent::Transparent(void):
  Phong(),
  reflective_brdf(new PerfectSpecular),
  specular_btdf(new PerfectTransmitter) {
}



// ---------------------------------------------------------------- copy constructor

Transparent::Transparent(const Transparent& r):
  Phong(r) {


  if (r.reflective_brdf)
    reflective_brdf = r.reflective_brdf->clone();
  else
    reflective_brdf = NULL;

  if (r.specular_btdf)
    specular_btdf = r.specular_btdf->clone();
  else
    specular_btdf = NULL;
}


// ---------------------------------------------------------------- clone

Transparent* Transparent::clone(void) const {
  return new Transparent(*this);
}


// ---------------------------------------------------------------- assignment operator

Transparent& Transparent::operator= (const Transparent& rhs) {
  if (this == &rhs)
    return *this;

  Phong::operator=(rhs);

  delete reflective_brdf;
  reflective_brdf = NULL;

  if (rhs.reflective_brdf)
    reflective_brdf = rhs.reflective_brdf->clone();

  delete specular_btdf;
  specular_btdf = NULL;

  if (rhs.specular_btdf)
    specular_btdf = rhs.specular_btdf->clone();

  return *this;
}


// ---------------------------------------------------------------- destructor

Transparent::~Transparent(void) {
  delete reflective_brdf;
  delete specular_btdf;
}

RGBColor Transparent::shade(ShadeRec& sr) {
  RGBColor L(Phong::shade(sr));

  Vector3D wo = -sr.ray.d;
  Vector3D wi;
  RGBColor fr = reflective_brdf->sample_f(sr, wo, wi);     // computes wi
  Ray reflected_ray(sr.hit_point, wi);

  if (specular_btdf) {
    L += sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1);
  } else {    // kr = 1.0
    Vector3D wt;
    RGBColor ft = specular_btdf->sample_f(sr, wo, wt);     // computes wt
    Ray transmutted_ray(sr.hit_point, wt);

    L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1) * std::fabs(sr.normal * wi);
    L += ft * sr.w.tracer_ptr->trace_ray(transmutted_ray, sr.depth + 1) * std::fabs(sr.normal * wt);
  }

  return L;
}
