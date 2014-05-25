#ifndef FBMTEXTURE_H
#define FBMTEXTURE_H

#include "RGBColor.h"
#include "LatticeNoise.h"
#include "Texture.h"

class FBmTexture: public Texture {

public:
  FBmTexture(void);
  FBmTexture(LatticeNoise* noise, const RGBColor& c = RGBColor(1.0), const float min = 0.0, const float max = 1.0);
  FBmTexture(const FBmTexture& fbm);
  FBmTexture& operator= (const FBmTexture& rhs);
  virtual FBmTexture* clone(void) const;
  virtual ~FBmTexture(void);

  void set_noise(LatticeNoise* _noise_ptr);
  void set_num_octaves(const int _num_octaves);
  void set_lacunarity(const float _lacunarity);
  void set_gain(const float _gain);
  void set_color(const RGBColor& c);
  void set_color(const float r,  const float g, const float b);
  void set_color(const float c);
  void set_min_value(const float m);
  void set_max_value(const float m);

  virtual RGBColor get_color(const ShadeRec& sr) const;

private:
  LatticeNoise* noise_ptr;
  RGBColor color;
  float min_value;  // scaling factor
  float max_value;  // scaling factor
};



inline void FBmTexture::set_noise(LatticeNoise* _noise_ptr) {
  noise_ptr = _noise_ptr;
}

inline void FBmTexture::set_num_octaves(const int _num_octaves) {
  noise_ptr->set_num_octaves(_num_octaves);
}

inline void FBmTexture::set_lacunarity(const float _lacunarity) {
  noise_ptr->set_lacunarity(_lacunarity);
}

inline void FBmTexture::set_gain(const float _gain) {
  noise_ptr->set_gain(_gain);
}

inline void FBmTexture::set_color(const RGBColor& c) {
  color = c;
}

inline void FBmTexture::set_color(const float r,  const float g, const float b) {
  color.r = r;
  color.b = b;
  color.g = g;
}

inline void FBmTexture::set_color(const float c) {
  color.r = c;
  color.b = c;
  color.g = c;
}

inline void FBmTexture::set_min_value(const float m) {
  min_value = m;
}

inline void FBmTexture::set_max_value(const float m) {
  max_value = m;
}

#endif // FBMTEXTURE_H
