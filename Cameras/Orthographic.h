#ifndef ORTHOGRAPHIC_H
#define ORTHOGRAPHIC_H

#include "Camera.h"
#include "Point2D.h"

class Orthographic: public Camera {

public:
  Orthographic();
  Orthographic(const Orthographic& o);
  virtual Camera* clone(void) const;
  Orthographic& operator= (const Orthographic& rhs);
  virtual ~Orthographic();

  void compute_direction(void);
  void compute_distance(void);

  virtual void render_scene(const World& w);

private:
  float d;
  Vector3D dir;
};

#endif // ORTHOGRAPHIC_H
