#include "Light.h"

Light::Light()
{
}

Light::Light(const Light & ls)
{
}

Light::~Light()
{
}

Light & Light::operator=(const Light & rhs)
{
	return *this;
}

RGBColor Light::L(ShadeRec & sr)
{
    return RGBColor(0.0f);
}

float Light::pdf(ShadeRec &sr)
{
    return 0.0f;
}

float Light::G(const ShadeRec &sr) const
{
    return 0.0f;
}
