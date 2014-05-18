#ifndef TRANSPARENT_H
#define TRANSPARENT_H

#include "Phong.h"
#include "PerfectSpecular.h"
#include "PerfectTransmitter.h"

class Transparent: public Phong {

public:
  Transparent(void);
  Transparent(const Transparent& r);
  virtual Transparent* clone(void) const;
  Transparent& operator= (const Transparent& rhs);
  virtual ~Transparent(void);

  void set_ior(const float i);
  void set_kr(const float k);
  void set_kt(const float k);

  virtual RGBColor shade(ShadeRec& sr);
  virtual RGBColor area_light_shade(ShadeRec& sr);

private:
  PerfectSpecular* reflective_brdf;
  PerfectTransmitter* specular_btdf;
};

inline void Transparent::set_ior(const float i) {
  specular_btdf->set_ior(i);
}

inline void Transparent::set_kr(const float k) {
  reflective_brdf->set_kr(k);
}

inline void Transparent::set_kt(const float k) {
  specular_btdf->set_kt(k);
}

#endif // TRANSPARENT_H
