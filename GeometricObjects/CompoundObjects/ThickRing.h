#ifndef THICKRING_H
#define THICKRING_H

#include "Compound.h"

class ThickRing: public Compound {
public:
  ThickRing(void);
  ThickRing(const double bottom, const double top, const double r1, const double r2);
  ThickRing(const ThickRing& sc);

  virtual ThickRing* clone (void) const;

  ThickRing& operator= (const ThickRing& rhs);

  virtual ~ThickRing(void);
};

#endif // THICKRING_H
