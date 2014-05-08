#include "Box.h"

#include "Vector3D.h"
#include "Normal.h"
#include "Rectangle.h"

Box::Box(void):
  Compound(),
  p0(-1.0),
  p1(1.0),
  bbox(p0, p1) {

  // bottom face: -ve y

  Rectangle* bottom_face = new Rectangle(Point3D(p0.x, p0.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Normal(0, -1, 0));
  objects.push_back(bottom_face);


  // bottom face: +ve y

  Rectangle* top_face = new Rectangle(Point3D(p0.x, p1.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Normal(0, 1, 0));
  objects.push_back(top_face);


  // back face: -ve z

  Rectangle* back_face = new Rectangle(Point3D(p0.x, p0.y, p0.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(0, 0 , -1));
  objects.push_back(back_face);


  // front face: +ve z

  Rectangle* front_face 	= new Rectangle(	Point3D(p0.x, p0.y, p1.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(0, 0 , 1));
  objects.push_back(front_face);


  // left face: -ve x

  Rectangle* left_face = new Rectangle(Point3D(p0.x, p0.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(-1, 0 , 0));
  objects.push_back(left_face);


  // right face: +ve x

  Rectangle* right_face = new Rectangle(Point3D(p1.x, p0.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(1, 0 , 0));
  objects.push_back(right_face);
}

Box::Box(const Point3D& min_corner, const Point3D& max_corner):
  Compound(),
  p0(min_corner),
  p1(max_corner),
  bbox(p0, p1) {

  // bottom face: -ve y

  Rectangle* bottom_face = new Rectangle(Point3D(p0.x, p0.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Normal(0, -1, 0));
  objects.push_back(bottom_face);


  // bottom face: +ve y

  Rectangle* top_face = new Rectangle(Point3D(p0.x, p1.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Normal(0, 1, 0));
  objects.push_back(top_face);


  // back face: -ve z

  Rectangle* back_face = new Rectangle(Point3D(p0.x, p0.y, p0.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(0, 0 , -1));
  objects.push_back(back_face);


  // front face: +ve z

  Rectangle* front_face 	= new Rectangle(	Point3D(p0.x, p0.y, p1.z),
                        Vector3D(p1.x - p0.x, 0, 0),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(0, 0 , 1));
  objects.push_back(front_face);


  // left face: -ve x

  Rectangle* left_face = new Rectangle(Point3D(p0.x, p0.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(-1, 0 , 0));
  objects.push_back(left_face);


  // right face: +ve x

  Rectangle* right_face = new Rectangle(Point3D(p1.x, p0.y, p0.z),
                        Vector3D(0, 0, p1.z - p0.z),
                        Vector3D(0, p1.y - p0.y, 0),
                        Normal(1, 0 , 0));
  objects.push_back(right_face);
}

Box::Box (const Box& bb):
  Compound(bb),
  p0(bb.p0),
  p1(bb.p1),
  bbox(bb.bbox) {
}

Box* Box::clone(void) const {
  return(new Box(*this));
}

Box& Box::operator= (const Box& rhs) {
  if (this == &rhs)
    return *this;

  Compound::operator=(rhs);

  p0		= rhs.p0;
  p1		= rhs.p1;
  bbox  = rhs.bbox;

  return *this;
}

Box::~Box (void) {
}

BBox Box::get_bounding_box(void) {
  return bbox;
}

//bool
//Box::shadow_hit(const Ray& ray, double& tmin) const {
//  if (bbox.hit(ray))
//    return (Compound::shadow_hit(ray, tmin));
//  else
//    return false;
//}

bool
Box::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  if (bbox.hit(ray))
    return Compound::hit(ray, tmin, sr);
  else
    return false;
}
