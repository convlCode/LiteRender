#include "World.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../BasicTools/stb_image_write.h"
#include <iostream>
#include "../Tracer/SingleSphere.h"
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

void World::render_scene() const
{
	RGBColor pixel_color;
	Ray ray;
	double zw = 200.0;
	double x, y;
	ray.d = Vector3D(0, 0, -1);

	const int nx = 400;
	const int ny = 400;
	RGB colorsData[nx][ny];
	for (int r = 0; r < vp.vres; r++) {
		for (int c = 0; c < vp.hres; c++) {
			pixel_color = background_color;
			x = vp.s * (c - 0.5 * (vp.hres - 1.0));
			y = vp.s * (r - 0.5 * (vp.vres - 1.0));
			ray.o = Vector3D(x, y, zw);
			pixel_color = tracer_ptr->trace_ray(ray);
			display_pixel(pixel_color, colorsData[ny - 1 - r][c]);
		}
	}
	stbi_write_jpg("image.jpg", nx, ny, 3, colorsData, 100);
}

void World::display_pixel(const RGBColor & pixel_color, RGB &color) const
{
	RGBColor mapped_color = pixel_color;

	if (vp.gamma != 1.0)
		mapped_color = mapped_color.powc(vp.inv_gamma);
	color.R = static_cast<unsigned char>(mapped_color.r * 255);
	color.G = static_cast<unsigned char>(mapped_color.g * 255);
	color.B = static_cast<unsigned char>(mapped_color.b * 255);
}

void World::build()
{
	vp.set_hres(400);
	vp.set_vres(400);
	vp.set_pixel_size(1);
	vp.set_gamma(1.0);
	background_color = black;

	tracer_ptr = new SingleSphere(this);
	sphere.set_center(0.0);
	sphere.set_radius(100);
}
