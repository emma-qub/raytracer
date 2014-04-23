#ifndef CONCAVECYLINDER_H
#define CONCAVECYLINDER_H

#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class ConcaveCylinder

class ConcaveCylinder: public GeometricObject {

public:

  ConcaveCylinder(void);
  ConcaveCylinder(const double bottom, const double top, const double radius);
  ConcaveCylinder(const ConcaveCylinder& cp);

  virtual ~ConcaveCylinder(void);

  virtual ConcaveCylinder* clone(void) const;
  ConcaveCylinder& operator= (const ConcaveCylinder& rhs);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

public:
  double y0;         // bottom y value
  double y1;         // top y value
  double radius;     // sphere radius
  double inv_radius; // stored only to avoid recalculations
};

#endif // CONCAVECYLINDER_H
