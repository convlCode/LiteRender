#ifndef WORLD_H
#define WORLD_H

#include "ViewPlane.h"
#include "GeometricObjects/Sphere.h"
#include "Tracer/RayCast.h"
#include "Cameras/Camera.h"
#include "Lights/Light.h"
#include <vector>
#include <QObject>
#include <QImage>
#include <QColor>

class World : public QObject
{
    Q_OBJECT
public:
	World();
    virtual ~World();

	void add_object(GeometricObject *object_ptr);
	void add_light(Light* light);
	void set_camera(Camera* c_ptr);
    void set_ambient(Light* a_ptr);
	void build();
	ShadeRec hit_objects(const Ray& ray);
	RGBColor max_to_one(const RGBColor& c) const;
    void clearScene();
    void render_scene();
private:
	void delete_objectes();
	void delete_lights();

signals:
    void renderComolete();
    void updateProgeress();
    //void clearCanvas();
public:
	ViewPlane vp;
	RGBColor background_color;
	Tracer* tracer_ptr;
	Camera* camera_ptr;
    Light*  ambient_ptr;
	std::vector<GeometricObject *> objects;
	std::vector<Light*>			lights;
    QImage* image;
    float   renderProgress;
    bool    stopRender;
};

inline void World::add_object(GeometricObject * object_ptr)
{
	objects.push_back(object_ptr);
}

inline void World::add_light(Light * light)
{
	lights.push_back(light);
}

inline void World::set_camera(Camera * c_ptr)
{
    camera_ptr = c_ptr;
}

inline void World::set_ambient(Light *a_ptr)
{
    ambient_ptr = a_ptr;
}

#endif 
