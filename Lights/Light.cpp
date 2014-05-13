#include "Light.h"

#include "Constants.h"

// ---------------------------------------------------------------------- default constructor

Light::Light(void):
  shadows(false) {
}

// ---------------------------------------------------------------------- dopy constructor

Light::Light(const Light& ls):
  shadows(ls.shadows) {
}


// ---------------------------------------------------------------------- assignment operator

Light& Light::operator= (const Light& rhs) {
  if (this == &rhs)
    return *this;

  shadows = rhs.shadows;

  return *this;
}


// ---------------------------------------------------------------------- destructor

Light::~Light(void) {
}



// ---------------------------------------------------------------------- L
// returns the radiance

RGBColor Light::L(ShadeRec& /*s*/) {
  return black;
}

float Light::G(const ShadeRec& /*sr*/) const {
  return 1.0;
}

float Light::pdf(const ShadeRec& /*sr*/) const {
  return 1.0;
}

bool Light::in_shadow(const Ray& /*ray*/, const ShadeRec& /*sr*/) const {
  return false;
}
