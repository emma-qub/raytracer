#ifndef CONSTANTCOLOR_H
#define CONSTANTCOLOR_H

#include "Texture.h"

class ConstantColor: public Texture {

public:
  ConstantColor(void);
  ConstantColor(const ConstantColor& cc);
  virtual ConstantColor* clone(void) const;
  virtual ~ConstantColor(void);

  void set_color(const float c);
  void set_color(const RGBColor& c);
  void set_color(const float r, const float g, const float b);
  virtual RGBColor get_color(const ShadeRec& sr) const;

private:
  RGBColor color;
};

inline void ConstantColor::set_color(const float c) {
  color.r = c;
  color.g = c;
  color.b = c;
}

inline void ConstantColor::set_color(const RGBColor& c) {
  color.r = c.r;
  color.g = c.g;
  color.b = c.b;
}

inline void ConstantColor::set_color(const float r, const float g, const float b) {
  color.r = r;
  color.g = g;
  color.b = b;
}

#endif // CONSTANTCOLOR_H
