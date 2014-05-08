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
  virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

  void scale_radiance(float radiance);
  void set_color(const RGBColor& c);
  void set_color(float r, float g, float b);
  void set_color(float c);
  void set_location(float x, float y, float z);

private:
  float ls;
  RGBColor color;
  Vector3D location;
};

inline void PointLight::scale_radiance(float radiance) {
  ls = radiance;
}

inline void PointLight::set_color(const RGBColor& c) {
  color = c;
}

inline void PointLight::set_color(float r, float g, float b) {
  color.r = r;
  color.g = g;
  color.b = b;
}

inline void PointLight::set_color(float c) {
  color.r = c;
  color.g = c;
  color.b = c;
}

inline void PointLight::set_location(float x, float y, float z) {
  location = Vector3D(x, y, z);
}

#endif // POINTLIGHT_H
