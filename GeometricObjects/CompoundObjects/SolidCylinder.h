#ifndef SOLIDCYLINDER_HXX
#define SOLIDCYLINDER_HXX

#include "Compound.h"
#include "OpenCylinder.h"
#include "Disk.h"

class SolidCylinder: public Compound {

public:
  SolidCylinder(void);
  SolidCylinder(const double bottom, const double top, const double radius);
  SolidCylinder(const SolidCylinder& sc);
  virtual SolidCylinder* clone (void) const;
  SolidCylinder& operator= (const SolidCylinder& rhs);
  virtual ~SolidCylinder(void);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;
};

#endif // SOLIDCYLINDER_HXX
