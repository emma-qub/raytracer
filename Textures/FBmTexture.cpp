#include "FBmTexture.h"

#include "Maths.h"
#include "CubicNoise.h"

FBmTexture::FBmTexture():
  Texture(),
  noise_ptr(NULL),
  color(white),
  min_value(0.0),
  max_value(1.0) {
}

FBmTexture::FBmTexture(LatticeNoise* noise, const RGBColor& c, const float min, const float max):
  Texture(),
  noise_ptr(noise),
  color(c),
  min_value(min),
  max_value(max) {
}

FBmTexture::FBmTexture(const FBmTexture& fbm):
  Texture(fbm),
  color(fbm.color),
  min_value(fbm.min_value),
  max_value(fbm.max_value) {

  if (fbm.noise_ptr)
    noise_ptr = fbm.noise_ptr->clone();
  else
    noise_ptr = NULL;
}

FBmTexture& FBmTexture::operator=(const FBmTexture& rhs) {
  if (this == &rhs)
    return *this;

  Texture::operator=(rhs);

  if (noise_ptr) {
    delete noise_ptr;
    noise_ptr = NULL;
  }

  if (rhs.noise_ptr)
    noise_ptr = rhs.noise_ptr->clone();

  color = rhs.color;
  min_value = rhs.min_value;
  max_value = rhs.max_value;

  return *this;
}

FBmTexture* FBmTexture::clone(void) const {
  return new FBmTexture(*this);
}

FBmTexture::~FBmTexture(void) {
  delete noise_ptr;
}

RGBColor FBmTexture::get_color(const ShadeRec& sr) const {
  float value = noise_ptr->value_fbm(sr.local_hit_point);
  value = min_value + (max_value - min_value) * value;

  return value * color;
}

