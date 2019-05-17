#include "Lambertian.h"
#include "../BasicTools/Constants.h"

Lambertian::Lambertian()
	:	BRDF(),kd{0.0f},cd{0.0f}
{
}

Lambertian::Lambertian(const Lambertian & lamb)
	:	BRDF(lamb),kd{lamb.kd},cd{lamb.cd}
{
}

Lambertian::~Lambertian()
{
}

Lambertian * Lambertian::clone() const
{
	return (new Lambertian(*this));
}

Lambertian & Lambertian::operator=(const Lambertian & rhs)
{
	if (this == &rhs)
		return (*this);
	BRDF::operator=(rhs);
	kd = rhs.kd;
	cd = rhs.cd;
	return *this;
}

RGBColor Lambertian::f(const ShadeRec & sr, const Vector3D & wo, const Vector3D & wi) const
{
	return  cd * kd * static_cast<const float>(invPI);
}

RGBColor Lambertian::rho(const ShadeRec & sr, const Vector3D & wo)
{
	return kd * cd;
}