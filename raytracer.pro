HEADERS += \
  BRDFs/BRDF.h \
  BRDFs/Lambertian.h \
  Cameras/Camera.h \
  Cameras/Pinhole.h \
  GeometricObjects/GeometricObject.h \
  GeometricObjects/PartObjects/ConvexPartCylinder.h \
  GeometricObjects/PartObjects/ConvexPartSphere.h \
  GeometricObjects/PartObjects/ConvexPartTorus.h \
  GeometricObjects/PartObjects/ConcavePartCylinder.h \
  GeometricObjects/PartObjects/ConcavePartSphere.h \
  GeometricObjects/PartObjects/ConcavePartTorus.h \
  GeometricObjects/PartObjects/OpenPartCylinder.h \
  GeometricObjects/PartObjects/OpenPartSphere.h \
  GeometricObjects/PartObjects/OpenPartTorus.h \
  GeometricObjects/Primitives/Disk.h \
  GeometricObjects/Primitives/Annulus.h \
  GeometricObjects/Primitives/OpenCone.h \
  GeometricObjects/Primitives/OpenCylinder.h \
  GeometricObjects/Primitives/Plane.h \
  GeometricObjects/Primitives/Rectangle.h \
  GeometricObjects/Primitives/Sphere.h \
  GeometricObjects/Primitives/Torus.h \
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
  Utilities/BBox.h \
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
    GeometricObjects/CompoundObjects/Compound.h

SOURCES += \
  BRDFs/BRDF.cpp \
  BRDFs/Lambertian.cpp \
  build/BuildShadedObjects.cpp \
  Cameras/Camera.cpp \
  Cameras/Pinhole.cpp \
  GeometricObjects/GeometricObject.cpp \
  GeometricObjects/PartObjects/ConvexPartCylinder.cpp \
  GeometricObjects/PartObjects/ConvexPartSphere.cpp \
  GeometricObjects/PartObjects/ConvexPartTorus.cpp \
  GeometricObjects/PartObjects/ConcavePartCylinder.cpp \
  GeometricObjects/PartObjects/ConcavePartSphere.cpp \
  GeometricObjects/PartObjects/ConcavePartTorus.cpp \
  GeometricObjects/PartObjects/OpenPartCylinder.cpp \
  GeometricObjects/PartObjects/OpenPartSphere.cpp \
  GeometricObjects/PartObjects/OpenPartTorus.cpp \
  GeometricObjects/Primitives/Disk.cpp \
  GeometricObjects/Primitives/Annulus.cpp \
  GeometricObjects/Primitives/OpenCone.cpp \
  GeometricObjects/Primitives/OpenCylinder.cpp \
  GeometricObjects/Primitives/Plane.cpp \
  GeometricObjects/Primitives/Rectangle.cpp \
  GeometricObjects/Primitives/Sphere.cpp \
  GeometricObjects/Primitives/Torus.cpp \
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
  Utilities/BBox.cpp \
  Utilities/Maths.cpp \
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
    GeometricObjects/CompoundObjects/Compound.cpp

INCLUDEPATH += \
  BRDFs \
  BRDFs \
  Cameras \
  GeometricObjects \
  GeometricObjects/PartObjects \
  GeometricObjects/Primitives \
  GeometricObjects/CompoundObjects \
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
