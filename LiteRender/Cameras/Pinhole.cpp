#include "Pinhole.h"

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
	return Vector3D();
}

void Pinhole::render_scene(const World & w)
{
}
