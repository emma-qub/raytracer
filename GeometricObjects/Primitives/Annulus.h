#ifndef ANNULUS_H
#define ANNULUS_H

#include "GeometricObject.h"

class Annulus: public GeometricObject {
public:
  Annulus(void);
  Annulus(const Point3D& c, const Normal& n, double i_r, double o_r);
  Annulus(const Annulus& annulus);
  virtual Annulus* clone(void) const;
  Annulus& operator=(const Annulus& rhs);
  virtual ~Annulus(void);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

private:
  Point3D center;
  Normal normal;
  double inner_radius;
  double outer_radius;
  double i_r_squared;
  double o_r_squared;
};

#endif // ANNULUS_H
