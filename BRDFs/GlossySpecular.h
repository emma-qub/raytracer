#ifndef GLOSSYSPECULAR_H
#define GLOSSYSPECULAR_H

#include "BRDF.h"

class GlossySpecular: public BRDF {

public:
  GlossySpecular(void);
  GlossySpecular(const GlossySpecular& gs);
  virtual GlossySpecular* clone(void) const;
  GlossySpecular& operator=(const GlossySpecular& rhs);
  virtual ~GlossySpecular(void);

  virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
  virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

  void set_ks(const float k);
  void set_exp(const float e);

  float ks;
  float exp;
};

inline void GlossySpecular::set_ks(const float k) {
  ks = k;
}

inline void GlossySpecular::set_exp(const float e) {
  exp = e;
}

#endif // GLOSSYSPECULAR_H
