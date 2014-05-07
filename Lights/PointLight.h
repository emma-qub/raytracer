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

  void scale_radiance(float radiance);
  void set_location(float x, float y, float z);

private:
  float ls;
  RGBColor color;
  Vector3D location;
};

inline void PointLight::scale_radiance(float radiance) {
  ls = radiance;
}

inline void PointLight::set_location(float x, float y, float z) {
  location = Vector3D(x, y, z);
}

#endif // POINTLIGHT_H
