#include "Material.h"

// ---------------------------------------------------------------- default constructor

Material::Material(void):
  shadows(true) {
}


// ---------------------------------------------------------------- copy constructor

Material::Material(const Material& m):
  shadows(m.shadows) {
}



// ---------------------------------------------------------------- assignment operator

Material& Material::operator= (const Material& rhs) {
  if (this == &rhs)
    return *this;

  shadows = rhs.shadows;

  return *this;
}


// ---------------------------------------------------------------- destructor

Material::~Material(void) {
}


RGBColor Material::get_Le(ShadeRec& /*sr*/) {
  return white;
}

// ---------------------------------------------------------------- shade

RGBColor Material::shade(ShadeRec& /*sr*/) {
  return black;
}
#include <QDebug>
RGBColor Material::area_light_shade(ShadeRec& /*sr*/) {
  qDebug() << "Material::area_light_shade";
  return black;
}

RGBColor Material::path_shade(ShadeRec& /*sr*/) {
  return black;
}
