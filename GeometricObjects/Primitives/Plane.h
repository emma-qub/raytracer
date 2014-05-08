#ifndef __PLANE__
#define __PLANE__

#include "GeometricObject.h"

//-------------------------------------------------------------------- class Plane

class Plane: public GeometricObject {

public:
  Plane(void);                                          // default constructor
  Plane(const Point3D& point, const Normal& normal);		// constructor
  Plane(const Plane& plane);                            // copy constructor
  virtual Plane* clone(void) const; 										// virtual copy constructor
  Plane& operator= (const Plane& rhs);    							// assignment operator
  virtual ~Plane(void);                         				// destructor

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, double& tmin) const;

private:
  Point3D 	a;   				// point through which plane passes
  Normal 		n;					// normal to the plane

  static const double kEpsilon;   // for shadows and secondary rays
};

#endif
