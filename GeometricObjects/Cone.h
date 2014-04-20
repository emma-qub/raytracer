#ifndef CONE_H
#define CONE_H

#include "GeometricObject.h"

class Cone: public GeometricObject {
public:
  Cone(void);
  Cone(double h, double r);
  Cone(const Cone& cone);
  virtual Cone* clone(void) const;
  Cone& operator=(const Cone& rhs);
  virtual ~Cone(void);
  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

private:
  double height;
  double radius;
  double hr;
  double h2r2;
};

#endif // CONE_H
