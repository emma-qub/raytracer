#ifndef GENERICGenericSphere_H
#define GENERICGenericSphere_H

// This file contains the declaration of the class GenericSphere

#include "GeometricObject.h"
#include "BBox.h"

class GenericSphere: public GeometricObject {

public:
  GenericSphere(void);
  GenericSphere(const GenericSphere& GenericSphere);
  virtual GenericSphere* clone(void) const;
  virtual	~GenericSphere(void);
  GenericSphere& operator= (const GenericSphere& genericSphere);

  BBox get_bounding_box(void) const;

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
};

#endif // GENERICGenericSphere_H
