#include "BRDF.h"

BRDF::BRDF()
{
}

BRDF::BRDF(const BRDF & brdf)
{
}

BRDF::~BRDF()
{
}

RGBColor BRDF::f(const ShadeRec & sr, const Vector3D & wo, const Vector3D & wi) const
{
	return RGBColor(0.0f, 0.0f, 0.0f);
}

RGBColor BRDF::sample_f(const ShadeRec & sr, const Vector3D & wo, Vector3D & wi) const
{
	return RGBColor(0.0f, 0.0f, 0.0f);
}

RGBColor BRDF::sample_f(const ShadeRec & sr, const Vector3D & wo, Vector3D & wi, float & pdf) const
{
	return RGBColor(0.0f, 0.0f, 0.0f);
}

RGBColor BRDF::rho(const ShadeRec & sr, const Vector3D & wo) const
{
	return RGBColor(0.0f, 0.0f, 0.0f);
}

BRDF & BRDF::operator=(const BRDF & rhs)
{
	return *this;
}
