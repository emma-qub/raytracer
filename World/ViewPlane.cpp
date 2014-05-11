// This file contains the definition the ViewPlane class

#include "ViewPlane.h"

// ---------------------------------------------------------------- default constructor

ViewPlane::ViewPlane(void):
  hres(400),
  vres(400),
  s(1.0),
  num_samples(1),
  gamma(1.0),
  inv_gamma(1.0),
  show_out_of_gamut(false),
  sampler_ptr(NULL),
  max_depth(1.0) {
}


// ---------------------------------------------------------------- copy constructor

ViewPlane::ViewPlane(const ViewPlane& vp):
  hres(vp.hres),
  vres(vp.vres),
  s(vp.s),
  num_samples(vp.num_samples),
  gamma(vp.gamma),
  inv_gamma(vp.inv_gamma),
  show_out_of_gamut(vp.show_out_of_gamut),
  max_depth(vp.max_depth) {

  //delete sampler_ptr;
  sampler_ptr = vp.sampler_ptr->clone();
}


// ---------------------------------------------------------------- assignment operator

ViewPlane& ViewPlane::operator= (const ViewPlane& rhs) {
  if (this == &rhs)
    return *this;

  hres 				= rhs.hres;
  vres 				= rhs.vres;
  s					= rhs.s;
  num_samples			= rhs.num_samples;
  gamma				= rhs.gamma;
  inv_gamma			= rhs.inv_gamma;
  show_out_of_gamut	= rhs.show_out_of_gamut;
  delete sampler_ptr;
  sampler_ptr = rhs.sampler_ptr->clone();
  max_depth = rhs.max_depth;

  return *this;
}


// -------------------------------------------------------------- destructor

ViewPlane::~ViewPlane(void) {
  delete sampler_ptr;
}
