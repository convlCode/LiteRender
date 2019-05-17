#include "Pinhole.h"
#include "../BasicTools/Constants.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../BasicTools/stb_image_write.h"
#include "../BasicTools/Point2D.h"

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
	RGBColor L;
	ViewPlane vp(w.vp);
	Ray ray;
	Point2D sp; //sample point in [0,1]*[0,1]
	Point2D pp; //sample point on a pixel
	vp.s /= zoom;
	ray.o = eye;

	const int nx = 400;
	const int ny = 400;
	RGB colorsData[nx][ny];
	for (int r = 0; r < vp.vres; r++) {
		for (int c = 0; c < vp.hres; c++) {
			L = w.background_color;
			for (int j = 0; j < vp.num_samples; ++j) {
				sp = vp.sampler_ptr->sample_unit_square();
				pp.x = vp.s*(c - 0.5f*vp.hres + sp.x);
				pp.y = vp.s*(r - 0.5f*vp.vres + sp.y);
				ray.d = get_direction(pp);
				L += w.tracer_ptr->trace_ray(ray);
			}
			L /= static_cast<float>(vp.num_samples);
			L = w.max_to_one(L);
			colorsData[ny - 1 - r][c].R = static_cast<unsigned char>(255.99*L.r);
			colorsData[ny - 1 - r][c].G = static_cast<unsigned char>(255.99*L.g);
			colorsData[ny - 1 - r][c].B = static_cast<unsigned char>(255.99*L.b);
		}
	}
	stbi_write_jpg("image.jpg", nx, ny, 3, colorsData, 100);
}
