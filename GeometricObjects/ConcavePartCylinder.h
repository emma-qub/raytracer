#ifndef CONCAVEPARTCYLINDER_H
#define CONCAVEPARTCYLINDER_H

// This file contains the declaration of the class ConcavePartCylinder
// This is a part sphere where the surface normal always points inwards
// If you study the code here you should be able to implement other part objects

#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class ConcavePartCylinder

class ConcavePartCylinder: public GeometricObject {

public:

  ConcavePartCylinder(void);

  ConcavePartCylinder(const double bottom,
                     const double top,
                     const double radius,
                     const double azimuth_min,	// in degrees
                     const double azimuth_max);	// in degrees

  ConcavePartCylinder(const double bottom, const double top, const double r);

  virtual ConcavePartCylinder* clone(void) const;

  ConcavePartCylinder(const ConcavePartCylinder& cp);

  virtual ~ConcavePartCylinder(void);

  ConcavePartCylinder& operator= (const ConcavePartCylinder& rhs);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

public:
  double y0;         // bottom y value
  double y1;         // top y value
  double radius;     // sphere radius
  double phi_min;    // minimum azimiuth angle in degrees measured counter clockwise from the +ve z axis
  double phi_max;    // maximum azimiuth angle in degrees measured counter clockwise from the +ve z axis
  double inv_radius; // stored only to avoid recalculations
};

#endif // CONCAVEPARTCYLINDER_H
