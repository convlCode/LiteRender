#ifndef _WORLD_H_
#define _WORLD_H_

#include "ViewPlane.h"
#include "../GeometricObjects/Sphere.h"
#include "../Tracer/RayCast.h"
#include "../Cameras/Camera.h"
#include <vector>

class World
{
public:
	World();
	~World();

	void add_object(GeometricObject *object_ptr);
	void set_camera(Camera* c_ptr);
	ShadeRec hit_bare_bones_objects(const Ray &ray) const;
	void build();

public:
	ViewPlane vp;
	RGBColor background_color;
	Sphere sphere;
	Tracer* tracer_ptr;
	Camera* camera_ptr;
	std::vector<GeometricObject *> objects;
};

inline void World::add_object(GeometricObject * object_ptr)
{
	objects.push_back(object_ptr);
}

inline void World::set_camera(Camera * c_ptr)
{
	camera_ptr = c_ptr;
}

#endif 
