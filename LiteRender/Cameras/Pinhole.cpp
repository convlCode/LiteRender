#include "Pinhole.h"
#include "../BasicTools/Constants.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../BasicTools/stb_image_write.h"

Pinhole::Pinhole()
	:Camera(), d{ 500.0f }, zoom{ 1.0f }
{
}

Pinhole::Pinhole(const Pinhole & ph)
	:Camera(ph),d{ph.d},zoom{ph.zoom}
{
}

Pinhole::~Pinhole()
{
}

Camera * Pinhole::clone(void) const
{
	return (new Pinhole(*this));
}

Pinhole & Pinhole::operator=(const Pinhole & rhs)
{
	if (this == &rhs)
		return *this;
	Camera::operator=(rhs);
	d = rhs.d;
	zoom = rhs.zoom;
	return *this;
}

Vector3D Pinhole::get_direction(const Point2D & p) const
{
	Vector3D direction = u * p.x + v * p.y - w * d; //float converted to double
	direction.normalize();
	return direction;
}

void Pinhole::display_pixel(const RGBColor & pixel_color, RGB &color,ViewPlane &vp) const
{
	RGBColor mapped_color = pixel_color;

	if (vp.gamma != 1.0)
		mapped_color = mapped_color.powc(vp.inv_gamma);
	color.R = static_cast<unsigned char>(mapped_color.r * 255);
	color.G = static_cast<unsigned char>(mapped_color.g * 255);
	color.B = static_cast<unsigned char>(mapped_color.b * 255);
}

void Pinhole::render_scene(const World & w)
{
	RGBColor pixel_color;
	ViewPlane vp(w.vp);
	Ray ray;
	float x, y;

	vp.s /= zoom;
	ray.o = eye;

	const int nx = 400;
	const int ny = 400;
	RGB colorsData[nx][ny];
	for (int r = 0; r < vp.vres; r++) {
		for (int c = 0; c < vp.hres; c++) {
			pixel_color = w.background_color;
			x = vp.s * (c - 0.5f * (vp.hres - 1));
			y = vp.s * (r - 0.5f * (vp.vres - 1));
			ray.d = get_direction(Point2D(x, y));
			pixel_color = w.tracer_ptr->trace_ray(ray);
			display_pixel(pixel_color, colorsData[ny - 1 - r][c], vp);
		}
	}
	stbi_write_jpg("image.jpg", nx, ny, 3, colorsData, 100);
}
