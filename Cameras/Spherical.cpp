#include "Spherical.h"

#include "RGBColor.h"
#include "World.h"
#include <cmath>

Spherical::Spherical():
  Camera(),
  psi_max(180),
  lambda_max(180) {
}

Spherical::Spherical(const Spherical& s):
  Camera(s),
  psi_max(s.psi_max),
  lambda_max(s.lambda_max) {
}

Spherical& Spherical::operator=(const Spherical& rhs) {
  if (this == &rhs)
    return (*this);

  Camera::operator=(rhs);

  psi_max = rhs.psi_max;
  lambda_max = rhs.lambda_max;

  return *this;
}

Spherical* Spherical::clone(void) const {
  return new Spherical(*this);
}

Spherical::~Spherical() {
}

Vector3D Spherical::ray_direction(const Point2D& pp, const int hres, const int vres, const float s) {
  // compute the normalized device coordinates

  Point2D pn(2.0 / (s * hres) * pp.x, 2.0 / (s * vres) * pp.y);

  // compute the angles lambda and phi in radians

  float lambda = pn.x * lambda_max * PI_ON_180;
  float psi = pn.y * psi_max * PI_ON_180;

  // compute the spherical azimuth and polar angles

  float phi = PI - lambda;
  float theta = 0.5 * PI - psi;

  float sin_theta = std::sin(theta);
  float sin_phi = std::sin(phi);
  float cos_theta = std::cos(theta);
  float cos_phi = std::cos(phi);

  Vector3D dir = sin_theta * sin_phi * u
               + cos_theta * v
               + sin_theta * cos_phi * w;

  return dir;

}

void Spherical::render_scene(const World& w) {
  RGBColor L;
  ViewPlane vp(w.vp);
  int hres = vp.hres;
  int vres = vp.vres;
  float s = vp.s;
  Ray ray;
  int depth = 0;
  Point2D sp;                 // sample point in [0, 1] x [0, 1]
  Point2D pp;                 // sample point on the pixel

  ray.o = eye;

  for (int r = 0; r < vres; r++) {    // up
    for (int c = 0; c < hres; c++) {  // accross
      L = black;

      for (int j = 0; j < vp.num_samples; j++) {
        sp = vp.sampler_ptr->sample_unit_square();
        pp.x = s * (c - 0.5 * hres + sp.x);
        pp.y = s * (r - 0.5 * vres + sp.y);
        ray.d = ray_direction(pp, hres, vres, s);

        L += w.tracer_ptr->trace_ray(ray, depth);
      }

      L /= vp.num_samples;
      L *= exposure_time;
      w.display_pixel(r, c, L);
    }
  }
}
