#ifndef _WORLD_H_
#define _WORLD_H_

#include "ViewPlane.h"
#include "../GeometricObjects/Sphere.h"
#include "../Tracer/SingleSphere.h"
#include <vector>

struct RGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

class World
{
public:
	World();
	~World();

	void add_object(GeometricObject *object_ptr);
	ShadeRec hit_bare_bones_objects(const Ray &ray) const;
	void render_scene() const;
	void display_pixel(const RGBColor &pixel_color,RGB &color) const;
	void build();

public:
	ViewPlane vp;
	RGBColor background_color;
	Sphere sphere;
	Tracer* tracer_ptr;
	std::vector<GeometricObject *> objects;
};

inline void World::add_object(GeometricObject * object_ptr)
{
	objects.push_back(object_ptr);
}

#endif 
