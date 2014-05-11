#include "SolidCylinder.h"
#include "Maths.h"
#include "Material.h"

SolidCylinder::SolidCylinder(void):
  Compound() {

  objects.push_back(new OpenCylinder);
  objects.push_back(new Disk(Point3D(0.0, -1.0, 0.0), Normal(0.0, -1.0, 0.0), 1.0));
  objects.push_back(new Disk(Point3D(0.0, 1.0, 0.0), Normal(0.0, 1.0, 0.0), 1.0));
}

SolidCylinder::SolidCylinder(const double bottom, const double top, const double radius):
  Compound() {

  objects.push_back(new OpenCylinder(bottom, top, radius));
  objects.push_back(new Disk(Point3D(0.0, bottom, 0.0), Normal(0.0, -1.0, 0.0), radius));
  objects.push_back(new Disk(Point3D(0.0, top, 0.0), Normal(0.0, 1.0, 0.0), radius));
}

SolidCylinder::SolidCylinder(const SolidCylinder& sc):
  Compound(sc) {
}

SolidCylinder* SolidCylinder::clone (void) const {
  return new SolidCylinder(*this);
}

SolidCylinder& SolidCylinder::operator=(const SolidCylinder& rhs) {
  if (this == &rhs)
    return *this;

  Compound::operator= (rhs);

  return *this;
}

SolidCylinder::~SolidCylinder(void) {
}

void SolidCylinder::set_wall_material(Material* m) {
  if (objects.size() >= 1 && objects[0])
    objects[0]->set_material(m);
}

void SolidCylinder::set_bottom_material(Material* m) {
  if (objects.size() >= 2 && objects[1])
    objects[1]->set_material(m);
}

void SolidCylinder::set_top_material(Material* m) {
  if (objects.size() >= 3 && objects[2])
    objects[2]->set_material(m);
}

bool SolidCylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  return Compound::hit(ray, tmin, sr);
}

bool SolidCylinder::shadow_hit(const Ray& ray, float& tmin) const {
  if (!shadows)
    return false;

  return Compound::shadow_hit(ray, tmin);
}
