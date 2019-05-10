#include "World.h"
#include <iostream>
#include "../Tracer/RayCast.h"
#include "../Cameras/Pinhole.h"

World::World()
	:background_color(black)
{
}


World::~World()
{
}

ShadeRec World::hit_bare_bones_objects(const Ray & ray) const
{
	ShadeRec sr(*this);
	double t, tmin = kHugeValue;
	for (size_t j = 0; j < objects.size(); j++) {
		if (objects[j]->hit(ray, t, sr)) {
			if (t < tmin) {
				sr.hit_an_object = true;
				tmin = t;
				sr.color = objects[j]->get_color();
			}
		}
	}
	return sr;
}




void World::build()
{
	vp.set_hres(400);
	vp.set_vres(400);
	vp.set_pixel_size(1);
	vp.set_gamma(1.0);
	background_color = black;

	tracer_ptr = new RayCast(this);

	Pinhole* pinhole_ptr = new Pinhole;
	pinhole_ptr->set_eye(0.0f, 0.0f, 1000.0f);
	pinhole_ptr->set_lookat(Point3D(0.0, 100.0, 0.0));
	pinhole_ptr->set_view_distance(1000);
	pinhole_ptr->compute_uvw();
	set_camera(pinhole_ptr);

	sphere.set_center(0.0);
	sphere.set_radius(100);
}
