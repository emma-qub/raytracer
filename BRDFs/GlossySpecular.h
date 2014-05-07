#ifndef GLOSSYSPECULAR_H
#define GLOSSYSPECULAR_H

#include "BRDF.h"

class GlossySpecular: public BRDF {

public:
  GlossySpecular(void);
  GlossySpecular(const GlossySpecular& gs);
  virtual BRDF* clone(void) const;
  GlossySpecular& operator=(const GlossySpecular& rhs);
  virtual ~GlossySpecular(void);

  virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;

  virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

  float ks;
  float exp;
};

#endif // GLOSSYSPECULAR_H
