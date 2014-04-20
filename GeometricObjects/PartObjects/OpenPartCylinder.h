#ifndef OPENPARTCYLINDER_H
#define OPENPARTCYLINDER_H

// This file contains the declaration of the class OpenPartCylinder
// This is a part sphere where the surface normal always points toward the camera
// If you study the code here you should be able to implement other part objects

#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class OpenPartCylinder

class OpenPartCylinder: public GeometricObject {

public:

  OpenPartCylinder(void);

  OpenPartCylinder(const double bottom,
                     const double top,
                     const double radius,
                     const double azimuth_min,	// in degrees
                     const double azimuth_max);	// in degrees

  OpenPartCylinder(const double bottom, const double top, const double r);

  virtual OpenPartCylinder* clone(void) const;

  OpenPartCylinder(const OpenPartCylinder& cp);

  virtual ~OpenPartCylinder(void);

  OpenPartCylinder& operator= (const OpenPartCylinder& rhs);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

public:
  double y0;         // bottom y value
  double y1;         // top y value
  double radius;     // sphere radius
  double phi_min;    // minimum azimiuth angle in degrees measured counter clockwise from the +ve z axis
  double phi_max;    // maximum azimiuth angle in degrees measured counter clockwise from the +ve z axis
  double inv_radius; // stored only to avoid recalculations
};

#endif // OPENPARTCYLINDER_H
