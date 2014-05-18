#include "PlaneChecker.h"

PlaneChecker::PlaneChecker(void):
  Texture(),
  size(1.0),
  outline_width(0.2),
  color1(1.0),
  color2(0.0),
  outline_color(0.0) {
}

PlaneChecker::PlaneChecker(const PlaneChecker& ch):
  Texture(ch),
  size(ch.size),
  outline_width(ch.outline_width),
  color1(ch.color1),
  color2(ch.color2),
  outline_color(ch.outline_color) {
}

PlaneChecker& PlaneChecker::operator= (const PlaneChecker& rhs) {
  if (this == &rhs)
    return *this;

  Texture::operator=(rhs);

  size = rhs.size;
  outline_width = rhs.outline_width;
  color1 = rhs.color1;
  color2 = rhs.color2;
  outline_color = rhs.outline_color;

  return *this;
}

PlaneChecker* PlaneChecker::clone(void) const {
  return new PlaneChecker (*this);
}

PlaneChecker::~PlaneChecker (void) {
}

RGBColor PlaneChecker::get_color(const ShadeRec& sr) const {

  float x = sr.local_hit_point.x;
  float z = sr.local_hit_point.z;
  int ix = floor(x / size);
  int iz = floor(z / size);
  float fx = x / size - ix;
  float fz = z / size - iz;
  float width = 0.5 * outline_width / size;
  bool in_outline = (fx < width || fx > 1.0 - width) || (fz < width || fz > 1.0 - width);

  if ((ix + iz) % 2 == 0) {
    if (!in_outline)
      return (color1);
  }
  else {
    if (!in_outline)
      return (color2);
  }

  return (outline_color);
}
