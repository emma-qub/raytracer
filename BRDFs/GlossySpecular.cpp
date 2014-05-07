#include "GlossySpecular.h"

#include <cmath>
#include "Constants.h"

GlossySpecular::GlossySpecular():
  BRDF(),
  ks(0.25),
  exp(5.0) {
}

GlossySpecular::GlossySpecular(const GlossySpecular& gs):
  BRDF(gs),
  ks(gs.ks),
  exp(gs.exp) {
}

BRDF* GlossySpecular::clone(void) const {
  return new GlossySpecular(*this);
}

GlossySpecular& GlossySpecular::operator=(const GlossySpecular& rhs) {
  if (this == &rhs)
    return (*this);

  BRDF::operator=(rhs);

  ks = rhs.ks;
  exp = rhs.exp;

  return *this;
}

GlossySpecular::~GlossySpecular(void) {
}

RGBColor GlossySpecular::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
  RGBColor L;
  float ndotwi = sr.normal * wi;
  Vector3D r(-wi + 2.0 * sr.normal * ndotwi);
  float rdotwo = r * wo;

  if (rdotwo > 0.0)
    L = ks * std::pow(rdotwo, exp);

  return L;
}

RGBColor GlossySpecular::rho(const ShadeRec& /*sr*/, const Vector3D& /*wo*/) const {
  return black;
}
