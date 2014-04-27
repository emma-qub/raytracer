#ifndef STEREOCAMERA_H
#define STEREOCAMERA_H

#include "Camera.h"

typedef enum {
  parallel,
  transverse
} ViewingType;

class StereoCamera: public Camera {
public:
  StereoCamera(void);
  StereoCamera(const StereoCamera& sc);
  virtual StereoCamera* clone(void) const;
  StereoCamera& operator=(const StereoCamera& rhs);
  virtual ~StereoCamera(void);

  void use_parallel_viewing();
  void use_transverse_viewing();
  void set_pixel_gap(int gap);
  void set_stereo_angle(float stereo_angle);
  void set_right_camera(Camera* r_camera);
  void set_left_camera(Camera* l_camera);

  void setup_cameras(void);
  virtual void render_scene(const World& w);

private:
  ViewingType viewing;        // specifies type of viewing
  int pixel_gap;              // gap in pixels between images
  float beta;                 // stereo separation angle
  Camera* left_camera_ptr;    // left eye camera
  Camera* right_camera_ptr;   // right eye camera
};

inline void StereoCamera::use_parallel_viewing() {
  viewing = parallel;
}

inline void StereoCamera::use_transverse_viewing() {
  viewing = transverse;
}

inline void StereoCamera::set_pixel_gap(int gap) {
  pixel_gap = gap;
}

inline void StereoCamera::set_stereo_angle(float stereo_angle) {
  beta = stereo_angle;
}

inline void StereoCamera::set_right_camera(Camera* r_camera) {
  delete right_camera_ptr;
  right_camera_ptr = r_camera;
}

inline void StereoCamera::set_left_camera(Camera* l_camera) {
  delete left_camera_ptr;
  left_camera_ptr = l_camera;
}

#endif // STEREOCAMERA_H
