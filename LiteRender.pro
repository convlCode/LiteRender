#-------------------------------------------------
#
# Project created by QtCreator 2019-05-17T09:14:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LiteRender
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES +=\
    BasicTools/Point2D.cpp \
    BasicTools/Point3D.cpp \
    BasicTools/Ray.cpp \
    BasicTools/RGBColor.cpp \
    BasicTools/ShadeRec.cpp \
    BasicTools/Vector3D.cpp \
    BxDFs/BRDF.cpp \
    BxDFs/Lambertian.cpp \
    Cameras/Camera.cpp \
    Cameras/Pinhole.cpp \
    GeometricObjects/GeometryObject.cpp \
    GeometricObjects/Sphere.cpp \
    Lights/Directional.cpp \
    Lights/Light.cpp \
    Materials/Material.cpp \
    Materials/Matte.cpp \
    Sampler/MultiJittered.cpp \
    Sampler/Regular.cpp \
    Sampler/Sampler.cpp \
    Tracer/RayCast.cpp \
    Tracer/Tracer.cpp \
    World/ViewPlane.cpp \
    World/World.cpp \
    main.cpp \
    mainwindow.cpp \
    Lights/Ambient.cpp \
    BxDFs/Glossyspecular.cpp \
    Materials/Phong.cpp \
    Materials/Emissive.cpp \
    GeometricObjects/Rectangle.cpp


HEADERS += \
    BasicTools/Constants.h \
    BasicTools/Maths.h \
    BasicTools/Point2D.h \
    BasicTools/Point3D.h \
    BasicTools/Ray.h \
    BasicTools/RGBColor.h \
    BasicTools/ShadeRec.h \
    BasicTools/Vector3D.h \
    BxDFs/BRDF.h \
    BxDFs/Lambertian.h \
    Cameras/Camera.h \
    Cameras/Pinhole.h \
    GeometricObjects/GeometryObject.h \
    GeometricObjects/Sphere.h \
    Lights/Directional.h \
    Lights/Light.h \
    Materials/Material.h \
    Materials/Matte.h \
    Materials/Phong.h \
    Sampler/MultiJittered.h \
    Sampler/Regular.h \
    Sampler/Sampler.h \
    Tracer/RayCast.h \
    Tracer/Tracer.h \
    World/ViewPlane.h \
    World/World.h \
    mainwindow.h \
    Lights/Ambient.h \
    BxDFs/Glossyspecular.h \
    Materials/Phong.h \
    Materials/Emissive.h \
    GeometricObjects/Rectangle.h


FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/liteRender.png \
    README.md
