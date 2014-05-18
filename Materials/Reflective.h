#ifndef REFLECTIVE_H
#define REFLECTIVE_H

#include "PerfectSpecular.h"
#include "Phong.h"

class Reflective: public Phong {

public:
  Reflective(void);
  Reflective(const Reflective& r);
  virtual Reflective* clone(void) const;
  Reflective& operator= (const Reflective& rhs);
  virtual ~Reflective(void);

  void set_kr(const float k);
  void set_cr(const RGBColor c);
  void set_cr(const float r, const float g, const float b);
  void set_cr(const float c);

  virtual RGBColor shade(ShadeRec& sr);
  virtual RGBColor area_light_shade(ShadeRec& sr);

private:
  PerfectSpecular* reflective_brdf;
};



inline void Reflective::set_kr(const float kr) {
  reflective_brdf->set_kr(kr);
}

inline void Reflective::set_cr(const RGBColor c) {
  reflective_brdf->set_cr(c);
}

inline void Reflective::set_cr(const float r, const float g, const float b) {
  reflective_brdf->set_cr(r, g, b);
}

inline void Reflective::set_cr(const float c) {
  reflective_brdf->set_cr(c);
}

#endif // REFLECTIVE_H
