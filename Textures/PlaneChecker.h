#ifndef PLANECHECKER_H
#define PLANECHECKER_H

#include "Texture.h"

class PlaneChecker: public Texture {
public:
  PlaneChecker(void);
  PlaneChecker(const PlaneChecker& ch);
  PlaneChecker& operator= (const PlaneChecker& rhs);
  virtual PlaneChecker* clone(void) const;
  virtual ~PlaneChecker(void);

  virtual RGBColor get_color(const ShadeRec& sr) const;

  void set_size(const float s);
  void set_outline_width(const float s);
  void set_color1(const RGBColor& c);
  void set_color1(const float r, const float g, const float b);
  void set_color1(const float c);
  void set_color2(const RGBColor& c);
  void set_color2(const float r, const float g, const float b);
  void set_color2(const float c);
  void set_outline_color(const RGBColor& c);
  void set_outline_color(const float r, const float g, const float b);
  void set_outline_color(const float c);

private:
  float size;
  float outline_width;
  RGBColor color1;
  RGBColor color2;
  RGBColor outline_color;
};

inline void PlaneChecker::set_size(const float s) {
  size = s;
}

inline void PlaneChecker::set_outline_width(const float s) {
  outline_width = s;
}

inline void PlaneChecker::set_color1(const RGBColor& c) {
  color1 = c;
}

inline void PlaneChecker::set_color1(const float c) {
  color1.r = c;
  color1.g = c;
  color1.b = c;
}

inline void PlaneChecker::set_color1(const float r, const float g, const float b) {
  color1.r = r;
  color1.g = g;
  color1.b = b;
}

inline void PlaneChecker::set_color2(const RGBColor& c) {
  color2 = c;
}

inline void PlaneChecker::set_color2(const float c) {
  color2.r = c;
  color2.g = c;
  color2.b = c;
}

inline void PlaneChecker::set_color2(const float r, const float g, const float b) {
  color2.r = r;
  color2.g = g;
  color2.b = b;
}

inline void PlaneChecker::set_outline_color(const RGBColor& c) {
  outline_color = c;
}

inline void PlaneChecker::set_outline_color(const float c) {
  outline_color.r = c;
  outline_color.g = c;
  outline_color.b = c;
}

inline void PlaneChecker::set_outline_color(const float r, const float g, const float b) {
  outline_color.r = r;
  outline_color.g = g;
  outline_color.b = b;
}

#endif // PLANECHECKER_H
