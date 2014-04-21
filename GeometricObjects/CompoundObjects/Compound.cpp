// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Constants.h"
#include "Compound.h"
#include "Material.h"
#include <iostream>


// ----------------------------------------------------------------  default constructor

Compound::Compound (void)
  : 	GeometricObject()
{
  std::cerr << "Compound constructor" << std::endl;
}


// ---------------------------------------------------------------- clone

Compound*
Compound::clone(void) const {
  std::cerr << "Compound clone" << std::endl;
  return (new Compound(*this));
}


// ---------------------------------------------------------------- copy constructor

Compound::Compound (const Compound& c)
  : GeometricObject(c) {

  std::cerr << "Compound copy constructor" << std::endl;
  copy_objects(c.objects);
}



// ---------------------------------------------------------------- assignment operator

Compound& Compound::operator= (const Compound& rhs) {
  std::cerr << "Compound operator=" << std::endl;

  if (this == &rhs)
    return (*this);

  GeometricObject::operator= (rhs);

  copy_objects(rhs.objects);

  return (*this);
}


// ---------------------------------------------------------------- destructor

Compound::~Compound(void) {
  std::cerr << "Compound destructor" << std::endl;

  delete_objects();
}


// ---------------------------------------------------------------- add_object

void
Compound::add_object(GeometricObject* object_ptr) {
  std::cerr << "Compound add_object" << std::endl;
  objects.push_back(object_ptr);
}


//------------------------------------------------------------------ set_material
// sets the same material on all objects

void
Compound::set_material(Material* material_ptr) {
  std::cerr << "Compound set_material" << std::endl;
  int num_objects = objects.size();

  for (int j = 0; j < num_objects; j++)
    objects[j]->set_material(material_ptr->clone());

  delete material_ptr;
  material_ptr = NULL;
}


//------------------------------------------------------------------ delete_objects
// Deletes the objects in the objects array, and erases the array.
// The array still exists, because it'ss an automatic variable, but it's empty

void Compound::delete_objects(void) {
  std::cerr << "Compound delete_objects" << std::endl;
  int num_objects = objects.size();

  for (int j = 0; j < num_objects; j++) {
    std::cerr << "Compound delete object #" << j << std::endl;
    delete objects[j];
    objects[j] = NULL;
  }

  std::cerr << "Compound objects deleted" << std::endl;
  objects.erase(objects.begin(), objects.end());
  std::cerr << "Compound array erased" << std::endl;
}


//------------------------------------------------------------------ copy_objects

void
Compound::copy_objects(const std::vector<GeometricObject*>& rhs_ojects) {
  std::cerr << "Compound copy_objects" << std::endl;
  delete_objects();
  int num_objects = rhs_ojects.size();

  for (int j = 0; j < num_objects; j++)
    objects.push_back(rhs_ojects[j]->clone());
}


//------------------------------------------------------------------ hit

bool
Compound::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  double		t;
  Normal		normal;
  Point3D		local_hit_point;
  bool		hit 		= false;
        tmin 		= kHugeValue;
  int 		num_objects	= objects.size();

  for (int j = 0; j < num_objects; j++)
    if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
      hit				= true;
      tmin 			= t;
      material_ptr	= objects[j]->get_material();	// lhs is GeometricObject::material_ptr
      normal			= sr.normal;
      local_hit_point	= sr.local_hit_point;
    }

  if (hit) {
    sr.t				= tmin;
    sr.normal 			= normal;
    sr.local_hit_point 	= local_hit_point;
  }

  return (hit);
}
