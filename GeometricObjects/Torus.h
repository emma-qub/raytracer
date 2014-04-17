#ifndef TORUS_H
#define TORUS_H

#include "GeometricObject.h"

class Torus: public GeometricObject {
public:
  Torus(void);
  Torus(double a, double b);
  Torus(const Torus& torus);
  Torus* clone(void) const;
  virtual ~Torus(void);
  Torus& operator=(const Torus& torus);
  Normal compute_normal(const Point3D& p) const;
  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;

private:
  double a;
  double b;

};

#endif // TORUS_H
