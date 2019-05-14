#include "RGBColor.h"
#include <cmath>
RGBColor::RGBColor()
	:r(0.0), g(0.0), b(0.0)
{
}

RGBColor::RGBColor(float c)
	:r{ c }, g{ c }, b{ c }
{
}

RGBColor::RGBColor(float _r, float _g, float _b)
	: r{ _r }, g{ _g }, b{ _b }
{
}

RGBColor::RGBColor(const RGBColor & c)
	: r{ c.r }, g{ c.g }, b{ c.b }
{
}

RGBColor::~RGBColor()
{
}

RGBColor & RGBColor::operator=(const RGBColor &rhs)
{
	if (this == &rhs)
		return (*this);
	r = rhs.r;
	g = rhs.g;
	b = rhs.b;
	return (*this);
}

RGBColor RGBColor::operator+(const RGBColor & v) const
{
	return RGBColor(r + v.r, g + v.g, b + v.b);
}

RGBColor RGBColor::operator-(const RGBColor & v) const
{
	return RGBColor(r - v.r, g - v.g, b - v.b);
}

RGBColor RGBColor::operator*(const float s) const
{
	return RGBColor(r*s, g*s, b*s);
}

RGBColor RGBColor::operator/(const float s) const
{
	return RGBColor(r / s, g / s, b / s);
}

RGBColor RGBColor::operator*(const RGBColor & c) const
{
	return RGBColor(r * c.r, g * c.g, b * c.b);
}

RGBColor & RGBColor::operator+=(const RGBColor & v)
{
	r += v.r;
	g += v.g;
	b += v.b;
	return *this;
}

RGBColor & RGBColor::operator-=(const RGBColor & v)
{
	r -= v.r;
	g -= v.g;
	b -= v.b;
	return *this;
}

RGBColor & RGBColor::operator*=(const float s)
{
	r *= s;
	g *= s;
	b *= s;
	return *this;
}

RGBColor & RGBColor::operator/=(const float s)
{
	r /= s;
	g /= s;
	b /= s;
	return *this;
}

bool RGBColor::operator==(const RGBColor & c) const
{
	if (c.r == r && c.g == g && c.b == b)
		return true;
	else
		return false;
}

float RGBColor::average() const
{
	return (0.3333333f*(r + g + b));
}

RGBColor RGBColor::powc(float p) const
{
	return RGBColor(std::pow(r, p), std::pow(g, p), std::pow(b, p));
}
