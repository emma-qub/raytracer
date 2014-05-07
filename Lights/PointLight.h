#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

class PointLight: public Light {

public:
  PointLight(void);
  PointLight(const PointLight& pl);
  PointLight& operator= (const PointLight& rhs);
  virtual Light* clone(void) const;
  virtual ~PointLight(void);

  virtual Vector3D get_direction(ShadeRec& sr);
  virtual RGBColor L(ShadeRec& sr);

private:
  float ls;
  RGBColor color;
  Vector3D location;
};

#endif // POINTLIGHT_H
