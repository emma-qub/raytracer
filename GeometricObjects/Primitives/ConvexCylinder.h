#ifndef CONVEXCYLINDER_H
#define CONVEXCYLINDER_H

#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class ConvexCylinder

class ConvexCylinder: public GeometricObject {

public:

  ConvexCylinder(void);
  ConvexCylinder(const double bottom, const double top, const double radius);
  ConvexCylinder(const ConvexCylinder& cp);
  virtual ~ConvexCylinder(void);
  virtual ConvexCylinder* clone(void) const;
  ConvexCylinder& operator= (const ConvexCylinder& rhs);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

public:
  double y0;         // bottom y value
  double y1;         // top y value
  double radius;     // sphere radius
  double inv_radius; // stored only to avoid recalculations
};

#endif // CONVEXCYLINDER_H
