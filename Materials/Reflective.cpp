#include "Reflective.h"

// ---------------------------------------------------------------- default constructor

Reflective::Reflective(void):
  Phong(),
  reflective_brdf(new PerfectSpecular) {
}



// ---------------------------------------------------------------- copy constructor

Reflective::Reflective(const Reflective& r):
  Phong(r) {

  if (r.reflective_brdf)
    reflective_brdf = r.reflective_brdf->clone();
  else
    reflective_brdf = NULL;
}


// ---------------------------------------------------------------- clone

Reflective* Reflective::clone(void) const {
  return new Reflective(*this);
}


// ---------------------------------------------------------------- assignment operator

Reflective& Reflective::operator= (const Reflective& rhs) {
  if (this == &rhs)
    return *this;

  Phong::operator=(rhs);

  delete reflective_brdf;
  reflective_brdf = NULL;

  if (rhs.reflective_brdf)
    reflective_brdf = rhs.reflective_brdf->clone();

  return *this;
}


// ---------------------------------------------------------------- destructor

Reflective::~Reflective(void) {
  delete reflective_brdf;
}


// ---------------------------------------------------------------- shade

RGBColor Reflective::shade(ShadeRec& sr) {
  RGBColor L(Phong::shade(sr));       // Direct illumination

  Vector3D wo 			= -sr.ray.d;
  Vector3D wi;
  RGBColor fr = reflective_brdf->sample_f(sr, wo, wi);
  Ray reflected_ray(sr.hit_point, wi);

  L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1) * (sr.normal * wi);

  return L;
}
#include <QDebug>
RGBColor Reflective::area_light_shade(ShadeRec& sr) {
  //qDebug() << "Reflective::area_light_shade";
  RGBColor L(Phong::shade(sr));       // Direct illumination

  Vector3D wo 			= -sr.ray.d;
  Vector3D wi;
  RGBColor fr = reflective_brdf->sample_f(sr, wo, wi);
  Ray reflected_ray(sr.hit_point, wi);

  L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1) * (sr.normal * wi);

  return L;
}
