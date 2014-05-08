#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__

class Material;

#include "Point3D.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"
#include "BBox.h"


//----------------------------------------------------------------------------------------------------- Class GeometricObject

class GeometricObject {

public:

  GeometricObject(void);                                    // default constructor
  GeometricObject(const GeometricObject& object);           // copy constructor
  virtual GeometricObject* clone(void) const = 0;           // virtual copy constructor
  virtual ~GeometricObject (void);                          // destructor

  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const = 0;

  Material* get_material(void) const;
  virtual void set_material(Material* mPtr);                // needs to virtual so that it can be overriden in Compound
  void set_shadows(bool b);

  virtual BBox get_bounding_box(void) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

protected:
  mutable Material* material_ptr;                           // mutable allows Compound::hit, Instance::hit and Grid::hit to assign to material_ptr. hit functions are const
  bool shadows;                                             // cast shadows or not

  GeometricObject& operator= (const GeometricObject& rhs);  // assignment operator
};


// ------------------------------------------------------------------------- get_material

inline Material*
GeometricObject::get_material(void) const {
  return material_ptr;
}

inline BBox GeometricObject::get_bounding_box(void) const {
  return BBox();
}

inline void GeometricObject::set_shadows(bool b) {
  shadows = b;
}

#endif
