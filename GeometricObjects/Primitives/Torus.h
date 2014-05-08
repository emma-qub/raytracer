#ifndef TORUS_H
#define TORUS_H

#include "GeometricObject.h"
#include "BBox.h"

class Torus: public GeometricObject {
public:
  Torus(void);
  Torus(double i_r, double o_r);
  Torus(const Torus& torus);
  Torus* clone(void) const;
  virtual ~Torus(void);
  Torus& operator=(const Torus& torus);

  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

  BBox get_bounding_box(void) const;

public:
  double a;
  double b;
  BBox bbox;

private:
  Normal compute_normal(const Point3D& p) const;
};

inline BBox Torus::get_bounding_box(void) const {
  return bbox;
}

#endif // TORUS_H
