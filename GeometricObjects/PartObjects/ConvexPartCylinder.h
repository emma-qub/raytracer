#ifndef CONVEXPARTCYLINDER_H
#define CONVEXPARTCYLINDER_H

// This file contains the declaration of the class ConvexPartCylinder
// This is a part sphere where the surface normal always points outwards
// If you study the code here you should be able to implement other part objects

#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class ConvexPartCylinder

class ConvexPartCylinder: public GeometricObject {

public:
  ConvexPartCylinder(void);
  ConvexPartCylinder(const double bottom, const double top, const double radius,
                     const double azimuth_min,	// in degrees
                     const double azimuth_max);	// in degrees
  ConvexPartCylinder(const double bottom, const double top, const double r);
  virtual ConvexPartCylinder* clone(void) const;
  ConvexPartCylinder(const ConvexPartCylinder& cp);
  virtual ~ConvexPartCylinder(void);
  ConvexPartCylinder& operator= (const ConvexPartCylinder& rhs);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

public:
  double y0;         // bottom y value
  double y1;         // top y value
  double radius;     // sphere radius
  double phi_min;    // minimum azimiuth angle in degrees measured counter clockwise from the +ve z axis
  double phi_max;    // maximum azimiuth angle in degrees measured counter clockwise from the +ve z axis
  double inv_radius; // stored only to avoid recalculations
};

#endif // CONVEXPARTCYLINDER_H
