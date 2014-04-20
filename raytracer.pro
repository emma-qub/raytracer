HEADERS += \
  BRDFs/BRDF.h \
  BRDFs/Lambertian.h \
  Cameras/Camera.h \
  Cameras/Pinhole.h \
  GeometricObjects/Cylinder.h \
  GeometricObjects/GeometricObject.h \
  GeometricObjects/Plane.h \
  GeometricObjects/Sphere.h \
  GeometricObjects/Torus.h \
  Lights/Ambient.h \
  Lights/Directional.h \
  Lights/Light.h \
  Materials/Material.h \
  Materials/Matte.h \
  Tracers/MultipleObjects.h \
  Tracers/RayCast.h \
  Tracers/Tracer.h \
  Tracers/SingleSphere.h \
  UserInterface/wxraytracer.h \
  Utilities/Constants.h \
  Utilities/Maths.h \
  Utilities/Matrix.h \
  Utilities/Normal.h \
  Utilities/Point2D.h \
  Utilities/Point3D.h \
  Utilities/Ray.h \
  Utilities/RGBColor.h \
  Utilities/ShadeRec.h \
  Utilities/Vector3D.h \
  World/ViewPlane.h \
  World/World.h \
    Utilities/BBox.h \
    GeometricObjects/Disk.h \
    GeometricObjects/Annulus.h

SOURCES += \
  BRDFs/BRDF.cpp \
  BRDFs/Lambertian.cpp \
  build/BuildShadedObjects.cpp \
  Cameras/Camera.cpp \
  Cameras/Pinhole.cpp \
  GeometricObjects/Cylinder.cpp \
  GeometricObjects/GeometricObject.cpp \
  GeometricObjects/Plane.cpp \
  GeometricObjects/Sphere.cpp \
  GeometricObjects/Torus.cpp \
  Lights/Ambient.cpp \
  Lights/Directional.cpp \
  Lights/Light.cpp \
  Materials/Material.cpp \
  Materials/Matte.cpp \
  Tracers/MultipleObjects.cpp \
  Tracers/RayCast.cpp \
  Tracers/SingleSphere.cpp \
  Tracers/Tracer.cpp \
  UserInterface/wxraytracer.cpp \
  Utilities/Matrix.cpp \
  Utilities/Normal.cpp \
  Utilities/Point2D.cpp \
  Utilities/Point3D.cpp \
  Utilities/Ray.cpp \
  Utilities/RGBColor.cpp \
  Utilities/ShadeRec.cpp \
  Utilities/Vector3D.cpp \
  World/ViewPlane.cpp \
  World/World.cpp \
  Utilities/Maths.cpp \
    Utilities/BBox.cpp \
    GeometricObjects/Disk.cpp \
    GeometricObjects/Annulus.cpp


INCLUDEPATH += \
  BRDFs \
  BRDFs \
  Cameras \
  GeometricObjects \
  Lights \
  Materials \
  Tracers \
  UserInterface \
  Utilities \
  World

LIBS += \
  -pthread \
  -lwx_gtk2u_xrc-2.8 \
  -lwx_gtk2u_html-2.8 \
  -lwx_gtk2u_qa-2.8 \
  -lwx_gtk2u_adv-2.8 \
  -lwx_gtk2u_core-2.8 \
  -lwx_baseu_xml-2.8 \
  -lwx_baseu_net-2.8 \
  -lwx_baseu-2.8

INCLUDEPATH += \
  /usr/include/wx-2.8/ \
  /usr/lib/wx/include/gtk2-unicode-release-2.8/ \
  /usr/lib/x86_64-linux-gnu/wx/include/gtk2-unicode-release-2.8/

QMAKE_CXXFLAGS += \
  -D_FILE_OFFSET_BITS=64 \
  -D_LARGE_FILES \
  -D__WXGTK__
