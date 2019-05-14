#include "World.h"
#include <iostream>
#include <algorithm>
#include "../Tracer/RayCast.h"
#include "../Cameras/Pinhole.h"
#include "../Sampler/MultiJittered.h"
#include "../Sampler/Regular.h"
#include "../Lights/Directional.h"
#include "../Materials/Matte.h"

World::World()
	:background_color(black),tracer_ptr{nullptr},
	camera_ptr{nullptr}
{
}


World::~World()
{
}

void World::build()
{
	int num_samples = 25;
	vp.set_hres(400);
	vp.set_vres(400);
	vp.set_pixel_size(0.5f);
	vp.set_gamma(1.0);
	vp.set_samples(num_samples);

	tracer_ptr = new RayCast(this);

	Pinhole* pinhole_ptr = new Pinhole;
	pinhole_ptr->set_eye(0.0f, 0.0f, 500.0f);
	pinhole_ptr->set_lookat(Point3D(0.0, 0.0, 0.0));
	pinhole_ptr->set_view_distance(600.0f);
	pinhole_ptr->compute_uvw();
	set_camera(pinhole_ptr);

	Directional* light_ptr1 = new Directional;
	light_ptr1->set_direction(50.0f, 50.0f, 50.0f);
	light_ptr1->scale_radiance(3.0f);
	add_light(light_ptr1);

	RGBColor light_purple(0.65f, 0.3f, 1.0f);

	Matte* matte_ptr = new Matte;
	matte_ptr->set_kd(0.75f);
	matte_ptr->set_cd(light_purple);
	
	Sphere*	sphere_ptr = new Sphere(Vector3D(5.0, 3.0, 0.0), 50.0);
	sphere_ptr->set_material(matte_ptr);							// light purple
	add_object(sphere_ptr);
}


ShadeRec World::hit_objects(const Ray & ray)
{
	ShadeRec	sr(*this);
	double		t;
	Vector3D	normal;
	Point3D		local_hit_point;
	double		tmin = kHugeValue;
	int 		num_objects = static_cast<int>(objects.size());

	for (int j = 0; j < num_objects; j++)
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object = true;
			tmin = t;
			sr.material_ptr = objects[j]->get_material();
			sr.hit_point = ray.o + ray.d * t;
			normal = sr.normal;
			local_hit_point = sr.local_hit_point;
		}

	if (sr.hit_an_object) {
		sr.t = static_cast<float>(tmin);
		sr.normal = normal;
		sr.local_hit_point = local_hit_point;
	}

	return sr;
}

RGBColor World::max_to_one(const RGBColor & c) const
{
	float max_value = std::max(c.r, std::max(c.g, c.b) );

	if (max_value > 1.0)
		return (c / max_value);
	else
		return (c);
}