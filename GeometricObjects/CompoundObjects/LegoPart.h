#ifndef LEGOPART_H
#define LEGOPART_H

#include "Compound.h"
#include "Point3D.h"

class LegoPart: public Compound {

public:
  LegoPart(void);
  LegoPart(const std::string& fileName);
  LegoPart(const LegoPart& lego);
  virtual LegoPart* clone(void) const;
  virtual LegoPart& operator= (const LegoPart& rhs);
  virtual ~LegoPart(void);

  void setLDrawLibraryPath(const std::string& ldrawLibPath);

  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
  virtual bool shadow_hit(const Ray& ray, float& tmin) const;

  void parseFile(void);
  Compound* parseSubFile(const std::string& fileName);

private:
  std::string ldrawLibraryPath;
  std::string legoFileName;
};

inline void LegoPart::setLDrawLibraryPath(const std::string& ldrawLibPath) {
  ldrawLibraryPath = ldrawLibPath;
}

bool is_back_slash(const char& c);

#endif // LEGOPART_H
