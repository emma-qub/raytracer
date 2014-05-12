#include "GlossySpecular.h"

#include <cmath>
#include "Constants.h"
#include "MultiJittered.h"

GlossySpecular::GlossySpecular():
  BRDF(),
  ks(0.25),
  cs(1.0),
  exp(5.0),
  metalic(false) {
}

GlossySpecular::GlossySpecular(const GlossySpecular& gs):
  BRDF(gs),
  ks(gs.ks),
  cs(gs.cs),
  exp(gs.exp),
  metalic(gs.metalic) {
}

GlossySpecular* GlossySpecular::clone(void) const {
  return new GlossySpecular(*this);
}

GlossySpecular& GlossySpecular::operator=(const GlossySpecular& rhs) {
  if (this == &rhs)
    return *this;

  BRDF::operator=(rhs);

  ks = rhs.ks;
  cs = rhs.cs;
  exp = rhs.exp;
  metalic = rhs.metalic;

  return *this;
}

GlossySpecular::~GlossySpecular(void) {
}

RGBColor GlossySpecular::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
  RGBColor L;
  float ndotwi = sr.normal * wi;
  Vector3D r(-wi + 2.0 * sr.normal * ndotwi);
  float rdotwo = r * wo;

  if (rdotwo > 0.0) {
    L = ks * std::pow(rdotwo, exp);
    if (metalic) {
      L = L * cs;
    }
  }

  return L;
}

RGBColor GlossySpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const {
  float ndotwo = sr.normal * wo;
  Vector3D r = -wo + 2.0 * sr.normal * ndotwo;    // direction of mirror reflection

  Vector3D w = r;
  Vector3D u = Vector3D(0.00424, 1.0, 0.00764) ^ w;
  u.normalize();
  Vector3D v = u ^ w;

  Point3D sp = sampler_ptr->sample_hemisphere();
  wi = sp.x * u + sp.y * v + sp.z * w;            // reflected ray direction

  if (sr.normal * wi < 0.0)                       // reflected ray is below surface
    wi = -sp.x * u - sp.y * v + sp.z * w;

  float phong_lobe = std::pow(r * wi, exp);
  pdf = phong_lobe * (sr.normal * wi);

  return ks * cs * phong_lobe;
}

RGBColor GlossySpecular::rho(const ShadeRec& /*sr*/, const Vector3D& /*wo*/) const {
  return black;
}

void GlossySpecular::set_samples(const int num_samples, const float exp) {
  sampler_ptr = new MultiJittered(num_samples);
  sampler_ptr->map_samples_to_hemisphere(exp);
}
