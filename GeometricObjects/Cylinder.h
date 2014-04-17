#ifndef CYLINDER_H
#define CYLINDER_H

#include "GeometricObject.h"

class Cylinder: public GeometricObject {

public:
  Cylinder(void);
  Cylinder(double r, double t, double b);
  Cylinder(const Cylinder& cylinder);

  virtual Cylinder* clone(void) const;

  virtual ~Cylinder(void);

  Cylinder& operator=(const Cylinder& cylinder);

  void set_radius(const double r);

  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;

private:
  double radius;
  double top;
  double bottom;
  double inv_radius;

  static const double kEpsilon;
};

inline void Cylinder::set_radius(const double r) {
  radius = r;
}

#endif // CYLINDER_H
