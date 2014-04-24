#ifndef TORUS_H
#define TORUS_H

#include "GeometricObject.h"
#include "BBox.h"

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
  BBox get_bounding_box(void) const;

private:
  double a;
  double b;
  BBox bbox;
};

inline BBox Torus::get_bounding_box(void) const {
  return bbox;
}

#endif // TORUS_H
