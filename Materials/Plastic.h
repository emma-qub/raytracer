#ifndef PLASTIC_H
#define PLASTIC_H

#include "Material.h"
#include "BRDF.h"

class Plastic: public Material {
public:
  Plastic(void);
  Plastic(const Plastic& p);
  virtual Material* clone(void) const;
  Plastic& operator= (const Plastic& rhs);
  virtual ~Plastic(void);

  void set_ambient_brdf(BRDF* brdf);
  void set_diffuse_brdf(BRDF* brdf);
  void set_specular_brdf(BRDF* brdf);

  virtual RGBColor shade(ShadeRec& sr);

private:
  BRDF* ambient_brdf;
  BRDF* diffuse_brdf;
  BRDF* specular_brdf;
};

inline void Plastic::set_ambient_brdf(BRDF* brdf) {
  if (ambient_brdf)
    delete ambient_brdf;
  ambient_brdf = brdf;
}

inline void Plastic::set_diffuse_brdf(BRDF* brdf) {
  if (diffuse_brdf)
    delete diffuse_brdf;
  diffuse_brdf = brdf;
}

inline void Plastic::set_specular_brdf(BRDF* brdf) {
  if (specular_brdf)
    delete specular_brdf;
  specular_brdf = brdf;
}

#endif // PLASTIC_H
