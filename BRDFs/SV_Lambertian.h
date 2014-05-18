#ifndef SV_LAMBERTIAN_H
#define SV_LAMBERTIAN_H

#include "BRDF.h"
#include "Texture.h"

class SV_Lambertian: public BRDF {

public:
  SV_Lambertian(void);
  SV_Lambertian(const SV_Lambertian& lamb);
  virtual SV_Lambertian* clone(void) const;
  virtual ~SV_Lambertian(void);
  SV_Lambertian& operator= (const SV_Lambertian& rhs);

  void set_ka(const float ka);
  void set_kd(const float kd);
  void set_cd(Texture* t_ptr);

  virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
  virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
  virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

private:
  float kd;
  Texture* cd;
};

inline void SV_Lambertian::set_ka(const float k) {
  kd = k;
}

inline void SV_Lambertian::set_kd(const float k) {
  kd = k;
}

inline void SV_Lambertian::set_cd(Texture* t_ptr) {
  delete cd;
  cd = t_ptr;
}

#endif // SV_LAMBERTIAN_H
