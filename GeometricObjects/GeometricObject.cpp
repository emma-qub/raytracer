// this file contains the definition of the class GeometricObject

#include "Material.h"
#include "GeometricObject.h"


// ---------------------------------------------------------------------- default constructor


GeometricObject::GeometricObject(void):
  material_ptr(NULL),
  shadows(true) {
}


// ---------------------------------------------------------------------- copy constructor

GeometricObject::GeometricObject(const GeometricObject& object):
  shadows(true) {

  if(object.material_ptr)
    material_ptr = object.material_ptr->clone();
  else  material_ptr = NULL;
}


// ---------------------------------------------------------------------- assignment operator

GeometricObject& GeometricObject::operator= (const GeometricObject& rhs) {
  if (this == &rhs)
    return *this;

  if (material_ptr) {
    delete material_ptr;
    material_ptr = NULL;
  }

  if (rhs.material_ptr)
    material_ptr = rhs.material_ptr->clone();

  shadows = true;

  return *this;
}


// ---------------------------------------------------------------------- destructor

GeometricObject::~GeometricObject (void) {
}


// ---------------------------------------------------------------- set_material

void GeometricObject::set_material(Material* mPtr) {
  material_ptr = mPtr;
}


bool GeometricObject::shadow_hit(const Ray& /*ray*/, float& /*tmin*/) const {
  return false;
}

Point3D GeometricObject::sample(void) {
  return Point3D();
}

Normal GeometricObject::get_normal(const Point3D& /*p*/) {
  return Normal();
}

float GeometricObject::pdf(const ShadeRec& /*sr*/) {
  return 0.0;
}
