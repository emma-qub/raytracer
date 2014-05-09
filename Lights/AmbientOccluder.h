#ifndef AMBIENTOCCLUDER_H
#define AMBIENTOCCLUDER_H

#include "Light.h"
#include "Sampler.h"
#include "PureRandom.h"
#include "MultiJittered.h"
#include "ShadeRec.h"
#include "World.h"

class AmbientOccluder: public Light {

public:
  AmbientOccluder(void);
  AmbientOccluder(const AmbientOccluder& ac);
  AmbientOccluder& operator=(const AmbientOccluder& rhs);
  virtual AmbientOccluder* clone(void) const;
  virtual ~AmbientOccluder(void);

  void set_sampler(Sampler* s_ptr);
  void set_samples(int n);
  void scale_radiance(const float b);
  void set_color(const float c);
  void set_color(const RGBColor& c);
  void set_color(const float r, const float g, const float b);
  void set_min_amount(float ma);

  virtual Vector3D get_direction(ShadeRec& sr);
  virtual RGBColor L(ShadeRec& sr);
  virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

private:
  Vector3D u;
  Vector3D v;
  Vector3D w;
  Sampler* sampler_ptr;
  float		ls;
  RGBColor	color;
  float min_amount;
};


inline void AmbientOccluder::scale_radiance(const float b) {
  ls = b;
}

inline void AmbientOccluder::set_color(const float c) {
  color.r = c; color.g = c; color.b = c;
}

inline void AmbientOccluder::set_color(const RGBColor& c) {
  color = c;
}

inline void AmbientOccluder::set_color(const float r, const float g, const float b) {
  color.r = r; color.g = g; color.b = b;
}

inline void AmbientOccluder::set_min_amount(float ma) {
  min_amount = ma;
}

#endif // AMBIENTOCCLUDER_H
