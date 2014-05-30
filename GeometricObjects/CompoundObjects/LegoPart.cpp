#include "LegoPart.h"

#include "Instance.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <QDebug>

LegoPart::LegoPart(void):
  Compound(),
  ldrawLibraryPath("/home/valentin/Documents/ldraw/"),
  legoFileName(ldrawLibraryPath+"parts/9460.dat") {

  parseFile();
}

LegoPart::LegoPart(const std::string& fileName):
  Compound(),
  ldrawLibraryPath("/home/valentin/Documents/ldraw/"),
  legoFileName(fileName) {

  parseFile();
}

LegoPart::LegoPart(const LegoPart& lego):
  Compound(lego),
  ldrawLibraryPath(lego.ldrawLibraryPath),
  legoFileName(lego.legoFileName) {

  parseFile();
}

LegoPart* LegoPart::clone(void) const {
  return new LegoPart(*this);
}

LegoPart& LegoPart::operator=(const LegoPart& rhs) {
  if (this == &rhs)
    return *this;

  Compound::operator=(rhs);

  ldrawLibraryPath = rhs.ldrawLibraryPath;
  legoFileName = rhs.legoFileName;

  return *this;
}

LegoPart::~LegoPart(void) {
}

bool LegoPart::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  return Compound::hit(ray, tmin, sr);
}

bool LegoPart::shadow_hit(const Ray& ray, float& tmin) const {
  if (!shadows)
    return false;

  return Compound::shadow_hit(ray, tmin);
}

void LegoPart::parseFile(void) {
  Instance* instance = new Instance(parseSubFile(legoFileName));
  instance->rotate_z(180);
  instance->translate(0, 10, 0);

  add_object(instance);
}

Compound* LegoPart::parseSubFile(const std::string& fileName) {
  std::ifstream file(fileName.c_str(), std::ios::in);

  Compound* res = new Compound;

  if (file) {
    std::string line;

    while (std::getline(file, line)) {
      line = line.substr(0, line.length()-1);

      int n, color;
      std::stringstream sstr;
      sstr << line;
      sstr >> n >> color;
      switch (n) {
      case 1:
      {
        int x, y, z, a, b, c, d, e, f, g, h, i;
        Matrix mat;
        std::string subFileName;
        sstr >> x >> y >> z
             >> a >> b >> c
             >> d >> e >> f
             >> g >> h >> i
             >> subFileName;
        mat.m[0][0] = a;
        mat.m[0][1] = b;
        mat.m[0][2] = c;
        mat.m[0][3] = x;
        mat.m[1][0] = d;
        mat.m[1][1] = e;
        mat.m[1][2] = f;
        mat.m[1][3] = y;
        mat.m[2][0] = g;
        mat.m[2][1] = h;
        mat.m[2][2] = i;
        mat.m[2][3] = z;
        mat.m[3][0] = 0;
        mat.m[3][1] = 0;
        mat.m[3][2] = 0;
        mat.m[3][3] = 1;
        if (subFileName[1] == '\\') {
          subFileName.replace(1, 1, 1, '/');
        }
        Compound* subPart = parseSubFile(ldrawLibraryPath+"p/"+subFileName);
        if (subPart == NULL) {
          subPart = parseSubFile(ldrawLibraryPath+"/parts/"+subFileName);
        }
        if (subPart != NULL) {
          Instance* instance = new Instance(subPart);
          instance->apply_matrix(mat);
          res->add_object(instance);
        }
        break;
      }
      case 3:
      {
        float x1, y1, z1;
        float x2, y2, z2;
        float x3, y3, z3;
        sstr >> x1 >> y1 >> z1
             >> x2 >> y2 >> z2
             >> x3 >> y3 >> z3;
        res->add_object(new Triangle(Point3D(x1, y1, z1), Point3D(x2, y2, z2), Point3D(x3, y3, z3)));
        break;
      }
      case 4:
      {
        float x1, y1, z1;
        float x2, y2, z2;
        float x3, y3, z3;
        float x4, y4, z4;
        sstr >> x1 >> y1 >> z1
             >> x2 >> y2 >> z2
             >> x3 >> y3 >> z3
             >> x4 >> y4 >> z4;
        res->add_object(new Triangle(Point3D(x1, y1, z1), Point3D(x2, y2, z2), Point3D(x3, y3, z3)));
        res->add_object(new Triangle(Point3D(x3, y3, z3), Point3D(x4, y4, z4), Point3D(x1, y1, z1)));
        break;
      }
      }
    }

    file.close();

  } else {
    std::cerr << "Error in LDrawParser::parseFile: cannot open " << fileName << std::endl;
    return NULL;
  }

  return res;
}
