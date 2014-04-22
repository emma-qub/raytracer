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

};

#endif // SOLIDCYLINDER_HXX
