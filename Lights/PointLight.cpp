#include "PointLight.h"
#include "ShadeRec.h"

PointLight::PointLight(void):
  Light(),
  ls(0.0),
  color(1.0),
  location(Vector3D(0.0)) {
}

PointLight::PointLight(const PointLight& pl):
  Light(pl),
  ls(pl.ls),
  color(pl.color),
  location(pl.location) {
}

PointLight& PointLight::operator=(const PointLight& rhs) {
  if (this == &rhs)
    return (*this);

  Light::operator=(rhs);

  ls = rhs.ls;
  color = rhs.color;
  location = rhs.location;

  return (*this);
}

Light* PointLight::clone(void) const {
  return new PointLight(*this);
}

PointLight::~PointLight(void) {
}

Vector3D PointLight::get_direction(ShadeRec& sr) {
  return (location - sr.hit_point).hat();
}

RGBColor PointLight::L(ShadeRec& /*sr*/) {
  return ls * color;
}
