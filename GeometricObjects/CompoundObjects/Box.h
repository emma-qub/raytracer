#ifndef BOX_H
#define BOX_H

#include "Compound.h"
#include "Point3D.h"

class Box: public Compound {

public:
  Box(void);
  Box(const Point3D& 	min_corner, const Point3D& max_corner);
  Box(const Box& bb);
  virtual Box* clone(void) const;
  virtual Box& operator= (const Box& rhs);
  virtual ~Box(void);

  virtual BBox get_bounding_box(void) const;

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

private:
  Point3D		p0; 	// minimum coordinate corner
  Point3D 	p1;		// maximum coordinate corner
  BBox      bbox;
};

#endif // BOX_H
