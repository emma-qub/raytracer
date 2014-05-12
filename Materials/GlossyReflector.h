#ifndef GLOSSYREFLECTOR_H
#define GLOSSYREFLECTOR_H

#include "Phong.h"

class GlossyReflector: public Phong {

public:
  GlossyReflector(void);
  GlossyReflector(const GlossyReflector& r);
  virtual GlossyReflector* clone(void) const;
  GlossyReflector& operator= (const GlossyReflector& rhs);
  virtual ~GlossyReflector(void);

  void set_samples(const int num_samples, const float exp);
  void set_kr(const float k);
  void set_exponent(const float exp);

  virtual RGBColor area_light_shade(ShadeRec& sr);

private:

  GlossySpecular* glossy_specular_brdf;
};


inline void
GlossyReflector::set_samples(const int num_samples, const float exp) {
  glossy_specular_brdf->set_samples(num_samples, exp);
}

inline void
GlossyReflector::set_kr(const float k) {
  glossy_specular_brdf->set_ks(k);
}

inline void
GlossyReflector::set_exponent(const float exp) {
  glossy_specular_brdf->set_exp(exp);
}

#endif // GLOSSYREFLECTOR_H
