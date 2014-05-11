// This file contians the definition of the class BRDF


#include "Constants.h"
#include "BRDF.h"

// ---------------------------------------------------------- default constructor

BRDF::BRDF(void):
  sampler_ptr(NULL) {
}


BRDF::BRDF(const BRDF& brdf) {
  if(brdf.sampler_ptr)
    sampler_ptr = brdf.sampler_ptr->clone();
  else
    sampler_ptr = NULL;
}



// --------------------------------------------------------------- assignment operator

BRDF& BRDF::operator= (const BRDF& rhs) {
  if (this == &rhs)
    return *this;

  if (sampler_ptr) {
    delete sampler_ptr;
    sampler_ptr = NULL;
  }

  if (rhs.sampler_ptr)
    sampler_ptr = rhs.sampler_ptr->clone();

  return *this;
}


// ---------------------------------------------------------- destructor

BRDF::~BRDF(void) {
  delete sampler_ptr;
}


// ------------------------------------------------------------------------ f

RGBColor BRDF::f(const ShadeRec& /*sr*/, const Vector3D& /*wo*/, const Vector3D& /*wi*/) const {
  return black;
}


// ------------------------------------------------------------------------ sample_f

RGBColor BRDF::sample_f(const ShadeRec& /*sr*/, const Vector3D& /*wo*/, Vector3D& /*wi*/) const {
  return black;
}


// ------------------------------------------------------------------------ sample_f

RGBColor BRDF::sample_f(const ShadeRec& /*sr*/, const Vector3D& /*wo*/, Vector3D& /*wi*/, float& /*pdf*/) const {
  return black;
}


// ------------------------------------------------------------------------ rho

RGBColor BRDF::rho(const ShadeRec& /*sr*/, const Vector3D& /*wo*/) const {
  return black;
}

void BRDF::set_sampler(Sampler *sp) {
  delete sampler_ptr;
  sampler_ptr = sp;
}
