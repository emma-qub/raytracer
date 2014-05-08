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
  void set_cs(const RGBColor& c);
  void set_cs(const float r, const float g, const float b);
  void set_cs(const float c);
  void set_exp(const float e);
  void set_metalic(bool b);

  float ks;
  RGBColor 	cs;
  float exp;
  bool metalic;
};

inline void GlossySpecular::set_ks(const float k) {
  ks = k;
}

inline void GlossySpecular::set_exp(const float e) {
  exp = e;
}

inline void GlossySpecular::set_cs(const RGBColor& c) {
  cs = c;
}

inline void GlossySpecular::set_cs(const float r, const float g, const float b) {
  cs.r = r; cs.g = g; cs.b = b;
}

inline void GlossySpecular::set_cs(const float c) {
  cs.r = c; cs.g = c; cs.b = c;
}

inline void GlossySpecular::set_metalic(bool b) {
  metalic = b;
}

#endif // GLOSSYSPECULAR_H
