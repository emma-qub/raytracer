#ifndef PERFECTSPECULAR_H
#define PERFECTSPECULAR_H

#include "BRDF.h"

class PerfectSpecular: public BRDF {

public:
  PerfectSpecular(void);
  PerfectSpecular(const PerfectSpecular& ps);
  virtual PerfectSpecular* clone(void) const;
  virtual ~PerfectSpecular(void);
  PerfectSpecular& operator= (const PerfectSpecular& rhs);

  virtual RGBColor sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi) const;

  void set_kr(const float kr);
  void set_cr(const RGBColor& c);
  void set_cr(const float r, const float g, const float b);
  void set_cr(const float c);

private:
  float kr;
  RGBColor cr;
};



// -------------------------------------------------------------- set_kr

inline void PerfectSpecular::set_kr(const float k) {
  kr = k;
}


// -------------------------------------------------------------- set_cr

inline void PerfectSpecular::set_cr(const RGBColor& c) {
  cr = c;
}


// ---------------------------------------------------------------- set_cr

inline void PerfectSpecular::set_cr(const float r, const float g, const float b) {
  cr.r = r; cr.g = g; cr.b = b;
}


// ---------------------------------------------------------------- set_cr

inline void PerfectSpecular::set_cr(const float c) {
  cr.r = c; cr.g = c; cr.b = c;
}

#endif // PERFECTSPECULAR_H
