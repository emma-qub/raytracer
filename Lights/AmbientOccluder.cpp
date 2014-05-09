#include "AmbientOccluder.h"
#include <iostream>

AmbientOccluder::AmbientOccluder(void):
  Light(),
  u(1.0, 0.0, 0.0),
  v(0.0, 1.0, 0.0),
  w(0.0, 0.0, 1.0),
  sampler_ptr(NULL),
  ls(1.0),
  color(1.0),
  min_amount(0.25) {
}

AmbientOccluder::AmbientOccluder(const AmbientOccluder& ac):
  Light(ac),
  u(ac.u),
  v(ac.v),
  w(ac.w),
  ls(ac.ls),
  color(ac.color),
  min_amount(ac.min_amount) {

  if(ac.sampler_ptr)
    sampler_ptr = ac.sampler_ptr->clone();
  else
    sampler_ptr = NULL;
}

AmbientOccluder& AmbientOccluder::operator=(const AmbientOccluder& rhs) {
  if (this == &rhs)
    return *this;

  Light::operator=(rhs);

  u = rhs.u;
  v = rhs.v;
  w = rhs.w;

  if (sampler_ptr) {
    delete sampler_ptr;
    sampler_ptr = NULL;
  }

  if (rhs.sampler_ptr)
    sampler_ptr = rhs.sampler_ptr->clone();

  ls 		= rhs.ls;
  color 	= rhs.color;
  min_amount = rhs.min_amount;

  return *this;
}

AmbientOccluder* AmbientOccluder::clone(void) const {
  return new AmbientOccluder(*this);
}

AmbientOccluder::~AmbientOccluder(void) {
  delete sampler_ptr;
}

void AmbientOccluder::set_sampler(Sampler* s_ptr) {
  if (sampler_ptr)
    delete sampler_ptr;

  sampler_ptr = s_ptr;
  sampler_ptr->map_samples_to_hemisphere(1.0);
}

void AmbientOccluder::set_samples(int n) {
  delete sampler_ptr;

  if (n > 1)
    sampler_ptr = new MultiJittered(n);
  else
    sampler_ptr = new PureRandom(1);

  sampler_ptr->map_samples_to_hemisphere(1.0);
}

Vector3D AmbientOccluder::get_direction(ShadeRec& /*sr*/) {
    Point3D sp = sampler_ptr->sample_hemisphere();
  return sp.x * u + sp.y * v + sp.z * w;
}

RGBColor AmbientOccluder::L(ShadeRec& sr) {
  w = sr.normal;
  // jitter up vector in case normal is vertical
  v = w ^ Vector3D(0.0072, 1.0, 0.0034);
  v.normalize();
  u = v ^ w;

  Ray shadow_ray;
  shadow_ray.o = sr.hit_point;
  shadow_ray.d = get_direction(sr);

  if (in_shadow(shadow_ray, sr))
    return min_amount * ls * color;
  else
    return ls * color;
}

bool AmbientOccluder::in_shadow(const Ray& ray, const ShadeRec& sr) const {
  float t;
  int num_objects = sr.w.objects.size();

  for (int j = 0; j < num_objects; j++) {
    if (sr.w.objects[j]->shadow_hit(ray, t))
      return true;
  }

  return false;
}
