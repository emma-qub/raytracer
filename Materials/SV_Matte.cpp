#include "SV_Matte.h"

// ---------------------------------------------------------------- default constructor

SV_Matte::SV_Matte (void):
  Material(),
  ambient_brdf(new SV_Lambertian),
  diffuse_brdf(new SV_Lambertian) {
}



// ---------------------------------------------------------------- copy constructor

SV_Matte::SV_Matte(const SV_Matte& m):
  Material(m) {

  if(m.ambient_brdf)
    ambient_brdf = m.ambient_brdf->clone();
  else
    ambient_brdf = NULL;

  if(m.diffuse_brdf)
    diffuse_brdf = m.diffuse_brdf->clone();
  else
    diffuse_brdf = NULL;
}


// ---------------------------------------------------------------- clone

Material* SV_Matte::clone(void) const {
  return new SV_Matte(*this);
}


// ---------------------------------------------------------------- assignment operator

SV_Matte& SV_Matte::operator= (const SV_Matte& rhs) {
  if (this == &rhs)
    return *this;

  Material::operator=(rhs);

  if (ambient_brdf) {
    delete ambient_brdf;
    ambient_brdf = NULL;
  }

  if (rhs.ambient_brdf)
    ambient_brdf = rhs.ambient_brdf->clone();

  if (diffuse_brdf) {
    delete diffuse_brdf;
    diffuse_brdf = NULL;
  }

  if (rhs.diffuse_brdf)
    diffuse_brdf = rhs.diffuse_brdf->clone();

  return *this;
}


// ---------------------------------------------------------------- destructor

SV_Matte::~SV_Matte(void) {

  if (ambient_brdf) {
    delete ambient_brdf;
    ambient_brdf = NULL;
  }

  if (diffuse_brdf) {
    delete diffuse_brdf;
    diffuse_brdf = NULL;
  }
}


// ---------------------------------------------------------------- shade

RGBColor SV_Matte::shade(ShadeRec& sr) {
  Vector3D 	wo 			= -sr.ray.d;
  RGBColor 	L 			= ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
  int 		num_lights	= sr.w.lights.size();

  for (int j = 0; j < num_lights; j++) {
    Light* light_ptr = sr.w.lights[j];
    Vector3D wi = light_ptr->get_direction(sr);
    wi.normalize();
    float ndotwi = sr.normal * wi;
    float ndotwo = sr.normal * wo;

    if (ndotwi > 0.0 && ndotwo > 0.0) {
      bool in_shadow = false;

      if (shadows && light_ptr->casts_shadows()) {
        Ray shadowsRay(sr.hit_point, wi);
        in_shadow = light_ptr->in_shadow(shadowsRay, sr);
      }

      if (!in_shadow)
        L += diffuse_brdf->f(sr, wo, wi) * light_ptr->L(sr) * light_ptr->G(sr) * ndotwi;
    }
  }

  return L;
}
