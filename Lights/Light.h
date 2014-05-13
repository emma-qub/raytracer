#ifndef __LIGHT__
#define __LIGHT__

#include "Vector3D.h"
#include "RGBColor.h"
#include "Ray.h"

class ShadeRec;


//-------------------------------------------------------------------- class Light

class Light {

public:
  Light(void);
  Light(const Light& ls);
  Light& operator=(const Light& rhs);
  virtual Light* clone(void) const = 0;
  virtual ~Light(void);

  virtual Vector3D get_direction(ShadeRec& sr) = 0;
  virtual RGBColor L(ShadeRec& sr);
  virtual float G(const ShadeRec& sr) const;
  virtual float pdf(const ShadeRec& sr) const;
  virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

  void set_shadows(bool b);
  bool casts_shadows(void) const;

protected:
    bool shadows;
};

inline void Light::set_shadows(bool b) {
  shadows = b;
}

inline bool Light::casts_shadows(void) const {
  return shadows;
}

#endif
