#include "Directional.h"

Directional::Directional()
	: Light(), ls{ 1.0f }, color{ 1.0f }, dir{ 0.0,1.0,0.0 }
{
}


Directional::Directional(const Directional & dl)
	: Light(dl), ls{ dl.ls }, color{ dl.color }, dir{ dl.dir }
{
}

Directional::~Directional()
{
}

Light * Directional::clone() const
{
	return (new Directional(*this));
}

Directional & Directional::operator=(const Directional & rhs)
{
	if (this == &rhs)
		return *this;
	Light::operator=(rhs);
	ls = rhs.ls;
	color = rhs.color;
	dir = rhs.dir;

	return (*this);
}

RGBColor Directional::L(ShadeRec & sr)
{
	return (ls * color);
}