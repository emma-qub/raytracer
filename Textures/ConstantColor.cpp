#include "ConstantColor.h"
#include "Constants.h"

ConstantColor::ConstantColor():
  Texture(),
  color(white) {
}

ConstantColor::ConstantColor(const ConstantColor& cc):
  Texture(cc),
  color(cc.color) {
}

ConstantColor* ConstantColor::clone(void) const {
  return new ConstantColor(*this);
}

ConstantColor::~ConstantColor(void) {
}

RGBColor ConstantColor::get_color(const ShadeRec& /*sr*/) const {
  return color;
}
