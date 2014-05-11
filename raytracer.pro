HEADERS += \
  BRDFs/BRDF.h \
  BRDFs/GlossySpecular.h \
  BRDFs/Lambertian.h \
  Cameras/Camera.h \
  Cameras/Fisheye.h\
#  Cameras/Orthographic.h \
  Cameras/Pinhole.h \
  Cameras/Spherical.h \
  Cameras/StereoCamera.h \
  Cameras/ThinLens.h \
  GeometricObjects/GeometricObject.h \
  GeometricObjects/Instance.h \
  GeometricObjects/BeveledObjects/BeveledBox.h \
  GeometricObjects/BeveledObjects/BeveledCylinder.h \
  GeometricObjects/BeveledObjects/BeveledWedge.h \
  GeometricObjects/CompoundObjects/Box.h \
  GeometricObjects/CompoundObjects/Compound.h \
  GeometricObjects/CompoundObjects/Grid.h \
  GeometricObjects/CompoundObjects/SolidCone.h \
  GeometricObjects/CompoundObjects/SolidCylinder.h \
  GeometricObjects/CompoundObjects/ThickRing.h \
  GeometricObjects/PartObjects/ConvexPartCylinder.h \
  GeometricObjects/PartObjects/ConvexPartSphere.h \
  GeometricObjects/PartObjects/ConvexPartTorus.h \
  GeometricObjects/PartObjects/ConcavePartCylinder.h \
  GeometricObjects/PartObjects/ConcavePartSphere.h \
  GeometricObjects/PartObjects/ConcavePartTorus.h \
  GeometricObjects/PartObjects/OpenPartCylinder.h \
  GeometricObjects/PartObjects/OpenPartSphere.h \
  GeometricObjects/PartObjects/OpenPartTorus.h \
  GeometricObjects/PartObjects/PartAnnulus.h \
  GeometricObjects/Primitives/Annulus.h \
  GeometricObjects/Primitives/ConvexCylinder.h \
  GeometricObjects/Primitives/ConcaveCylinder.h \
  GeometricObjects/Primitives/Disk.h \
  GeometricObjects/Primitives/GenericSphere.h \
  GeometricObjects/Primitives/OpenCone.h \
  GeometricObjects/Primitives/OpenCylinder.h \
  GeometricObjects/Primitives/Plane.h \
  GeometricObjects/Primitives/Rectangle.h \
  GeometricObjects/Primitives/Sphere.h \
  GeometricObjects/Primitives/Torus.h \
  GeometricObjects/Triangles/FlatMeshTriangle.h \
  GeometricObjects/Triangles/MeshTriangle.h \
  GeometricObjects/Triangles/SmoothMeshTriangle.h \
  GeometricObjects/Triangles/SmoothTriangle.h \
  GeometricObjects/Triangles/Triangle.h \
  Lights/Ambient.h \
  Lights/AmbientOccluder.h \
  Lights/Directional.h \
  Lights/Light.h \
  Lights/PointLight.h \
  Materials/Material.h \
  Materials/Matte.h \
  Materials/Phong.h \
  Materials/Plastic.h \
  Tracers/MultipleObjects.h \
  Tracers/RayCast.h \
  Tracers/Tracer.h \
  Tracers/SingleSphere.h \
  Tracers/Whitted.h \
  Samplers/Hammersley.h \
  Samplers/Jittered.h \
  Samplers/MultiJittered.h \
  Samplers/NRooks.h \
  Samplers/PureRandom.h \
  Samplers/Regular.h \
  Samplers/Sampler.h \
  UserInterface/wxraytracer.h \
  Utilities/BBox.h \
  Utilities/Constants.h \
  Utilities/Maths.h \
  Utilities/Matrix.h \
  Utilities/Mesh.h \
  Utilities/Normal.h \
  Utilities/ply.h \
  Utilities/Point2D.h \
  Utilities/Point3D.h \
  Utilities/Ray.h \
  Utilities/RGBColor.h \
  Utilities/ShadeRec.h \
  Utilities/Vector3D.h \
  World/ViewPlane.h \
  World/World.h \
    GeometricObjects/CompoundObjects/FlatRimmedBowl.h \
    GeometricObjects/CompoundObjects/RoundRimmedBowl.h \
    Textures/Texture.h \
    Textures/ConstantColor.h

SOURCES += \
  BRDFs/BRDF.cpp \
  BRDFs/GlossySpecular.cpp \
  BRDFs/Lambertian.cpp \
  build/Build2.cpp \
  build/BuildShadedObjects.cpp \
  Cameras/Camera.cpp \
  Cameras/Fisheye.cpp \
#  Cameras/Orthographic.cpp \
  Cameras/Pinhole.cpp \
  Cameras/Spherical.cpp \
  Cameras/StereoCamera.cpp \
  Cameras/ThinLens.cpp \
  GeometricObjects/GeometricObject.cpp \
  GeometricObjects/Instance.cpp \
  GeometricObjects/BeveledObjects/BeveledBox.cpp \
  GeometricObjects/BeveledObjects/BeveledCylinder.cpp \
  GeometricObjects/BeveledObjects/BeveledWedge.cpp \
  GeometricObjects/CompoundObjects/Box.cpp \
  GeometricObjects/CompoundObjects/Compound.cpp \
  GeometricObjects/CompoundObjects/Grid.cpp \
  GeometricObjects/CompoundObjects/SolidCone.cpp \
  GeometricObjects/CompoundObjects/SolidCylinder.cpp \
  GeometricObjects/CompoundObjects/ThickRing.cpp \
  GeometricObjects/PartObjects/ConvexPartCylinder.cpp \
  GeometricObjects/PartObjects/ConvexPartSphere.cpp \
  GeometricObjects/PartObjects/ConvexPartTorus.cpp \
  GeometricObjects/PartObjects/ConcavePartCylinder.cpp \
  GeometricObjects/PartObjects/ConcavePartSphere.cpp \
  GeometricObjects/PartObjects/ConcavePartTorus.cpp \
  GeometricObjects/PartObjects/OpenPartCylinder.cpp \
  GeometricObjects/PartObjects/OpenPartSphere.cpp \
  GeometricObjects/PartObjects/OpenPartTorus.cpp \
  GeometricObjects/PartObjects/PartAnnulus.cpp \
  GeometricObjects/Primitives/Annulus.cpp \
  GeometricObjects/Primitives/ConvexCylinder.cpp \
  GeometricObjects/Primitives/ConcaveCylinder.cpp \
  GeometricObjects/Primitives/Disk.cpp \
  GeometricObjects/Primitives/GenericSphere.cpp \
  GeometricObjects/Primitives/OpenCone.cpp \
  GeometricObjects/Primitives/OpenCylinder.cpp \
  GeometricObjects/Primitives/Plane.cpp \
  GeometricObjects/Primitives/Rectangle.cpp \
  GeometricObjects/Primitives/Sphere.cpp \
  GeometricObjects/Primitives/Torus.cpp \
  GeometricObjects/Triangles/FlatMeshTriangle.cpp \
  GeometricObjects/Triangles/MeshTriangle.cpp \
  GeometricObjects/Triangles/SmoothMeshTriangle.cpp \
  GeometricObjects/Triangles/SmoothTriangle.cpp \
  GeometricObjects/Triangles/Triangle.cpp \
  Lights/Ambient.cpp \
  Lights/AmbientOccluder.cpp \
  Lights/Directional.cpp \
  Lights/Light.cpp \
  Lights/PointLight.cpp \
  Materials/Material.cpp \
  Materials/Matte.cpp \
  Materials/Phong.cpp \
  Materials/Plastic.cpp \
  Samplers/Hammersley.cpp \
  Samplers/Jittered.cpp \
  Samplers/MultiJittered.cpp \
  Samplers/NRooks.cpp \
  Samplers/PureRandom.cpp \
  Samplers/Regular.cpp \
  Samplers/Sampler.cpp \
  Tracers/MultipleObjects.cpp \
  Tracers/RayCast.cpp \
  Tracers/SingleSphere.cpp \
  Tracers/Tracer.cpp \
  Tracers/Whitted.cpp \
  UserInterface/wxraytracer.cpp \
  Utilities/BBox.cpp \
  Utilities/Maths.cpp \
  Utilities/Matrix.cpp \
  Utilities/Mesh.cpp \
  Utilities/Normal.cpp \
  Utilities/ply.c \
  Utilities/Point2D.cpp \
  Utilities/Point3D.cpp \
  Utilities/Ray.cpp \
  Utilities/RGBColor.cpp \
  Utilities/ShadeRec.cpp \
  Utilities/Vector3D.cpp \
  World/ViewPlane.cpp \
  World/World.cpp \
    GeometricObjects/CompoundObjects/FlatRimmedBowl.cpp \
    GeometricObjects/CompoundObjects/RoundRimmedBowl.cpp \
    Textures/Texture.cpp \
    Textures/ConstantColor.cpp

INCLUDEPATH += \
  BRDFs \
  BRDFs \
  Cameras \
  GeometricObjects \
  GeometricObjects/BeveledObjects/ \
  GeometricObjects/CompoundObjects \
  GeometricObjects/PartObjects \
  GeometricObjects/Primitives \
  GeometricObjects/Triangles \
  Lights \
  Materials \
  Samplers \
  Textures \
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

CONFIG += c++11
