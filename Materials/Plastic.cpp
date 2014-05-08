#include "Plastic.h"

Plastic::Plastic(void):
  Material(),
  ambient_brdf(NULL),
  diffuse_brdf(NULL),
  specular_brdf(NULL) {
}

Plastic::Plastic(const Plastic& p):
  Material(p) {

  if (p.ambient_brdf)
    ambient_brdf = p.ambient_brdf->clone();
  else
    ambient_brdf = NULL;

  if (p.diffuse_brdf)
    diffuse_brdf = p.diffuse_brdf->clone();
  else
    diffuse_brdf = NULL;

  if (p.specular_brdf)
    specular_brdf = p.specular_brdf->clone();
  else
    specular_brdf = NULL;
}

Material* Plastic::clone(void) const {
  return new Plastic(*this);
}

Plastic& Plastic::operator= (const Plastic& rhs) {
  if (this == &rhs)
    return *this;

  Material::operator=(rhs);

  delete ambient_brdf;
  ambient_brdf = NULL;

  if (rhs.ambient_brdf)
    ambient_brdf = rhs.ambient_brdf->clone();

  delete diffuse_brdf;
  diffuse_brdf = NULL;

  if (rhs.diffuse_brdf)
    diffuse_brdf = rhs.diffuse_brdf->clone();

  delete specular_brdf;
  specular_brdf = NULL;

  if (rhs.specular_brdf)
    specular_brdf = rhs.specular_brdf->clone();

  return *this;
}

Plastic::~Plastic(void) {
  delete ambient_brdf;
  delete diffuse_brdf;
  delete specular_brdf;
}

RGBColor
Plastic::shade(ShadeRec& sr) {
  Vector3D 	wo 			= -sr.ray.d;
  RGBColor 	L 			= ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
  int 		num_lights	= sr.w.lights.size();

  for (int j = 0; j < num_lights; j++) {
    Vector3D wi = sr.w.lights[j]->get_direction(sr);
    float ndotwi = sr.normal * wi;

    if (ndotwi > 0.0){
      bool in_shadow = false;

      if (shadows && sr.w.lights[j]->casts_shadows()) {
        Ray shadowsRay(sr.hit_point, wi);
        in_shadow = sr.w.lights[j]->in_shadow(shadowsRay, sr);
      }

      if (!in_shadow)
        L += (diffuse_brdf->f(sr, wo, wi) + specular_brdf->f(sr, wo, wi))
           * sr.w.lights[j]->L(sr) * ndotwi;
    }
  }

  return L;
}
