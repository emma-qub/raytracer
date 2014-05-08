#include "StereoCamera.h"
#include "Constants.h"
#include "ViewPlane.h"
#include "Ray.h"
#include "World.h"
#include <cmath>

StereoCamera::StereoCamera() :
  Camera(),
  viewing(parallel),
  pixel_gap(5),
  beta(0.75),                 // in degrees;
  left_camera_ptr(nullptr),
  right_camera_ptr(nullptr) {
}

StereoCamera::StereoCamera(const StereoCamera& sc):
  Camera(sc),
  viewing(sc.viewing),
  pixel_gap(sc.pixel_gap),
  beta(sc.beta),                 // in degrees;
  left_camera_ptr(sc.left_camera_ptr->clone()),
  right_camera_ptr(sc.right_camera_ptr->clone()) {
}

StereoCamera* StereoCamera::clone(void) const {
  return new StereoCamera(*this);
}

StereoCamera& StereoCamera::operator=(const StereoCamera& rhs) {
  if (this == &rhs)
    return *this;

  Camera::operator= (rhs);

  viewing = rhs.viewing;
  pixel_gap = rhs.pixel_gap;
  beta = rhs.beta;                 // in degrees;
  left_camera_ptr = rhs.left_camera_ptr->clone();
  right_camera_ptr = rhs.right_camera_ptr->clone();

  return *this;
}

StereoCamera::~StereoCamera(void) {
  delete right_camera_ptr;
  delete left_camera_ptr;
}

void StereoCamera::setup_cameras() {
  double r = eye.distance(lookat);
  double x = r * std::tan(0.5 * beta * PI_ON_180);   // half the camera separation

  left_camera_ptr->set_eye(eye - x * u);
  left_camera_ptr->set_lookat(lookat - x * u);
  left_camera_ptr->compute_uvw();

  right_camera_ptr->set_eye(eye + x * u);
  right_camera_ptr->set_lookat(lookat + x * u);
  right_camera_ptr->compute_uvw();
}

void StereoCamera::render_scene(const World& w) {
  ViewPlane vp = w.vp;
  int hres = vp.hres;

  double r = eye.distance(lookat);
  double x = r * std::tan(0.5 * beta * PI_ON_180);

  if (viewing == parallel) {
    left_camera_ptr->render_stereo(w, x, 0);
    right_camera_ptr->render_stereo(w, -x, hres + pixel_gap);
  }

  if (viewing == transverse) {
    right_camera_ptr->render_stereo(w, -x, 0);
    left_camera_ptr->render_stereo(w, x, hres + pixel_gap);
  }
}
