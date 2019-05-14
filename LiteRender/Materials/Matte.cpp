#include "Matte.h"

Matte::Matte()
	:Material(),
	ambient_brdf{ new Lambertian },
	diffuse_brdf{ new Lambertian }
{
}

Matte::Matte(const Matte & m)
	:	Material(m)
{
	if (m.ambient_brdf)
		ambient_brdf = m.ambient_brdf->clone();
	else
		ambient_brdf = nullptr;

	if (m.diffuse_brdf)
		diffuse_brdf = m.diffuse_brdf->clone();
	else
		diffuse_brdf = nullptr;
}

Matte::~Matte()
{
	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = nullptr;
	}
	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = nullptr;
	}
}

Material * Matte::clone() const
{
	return (new Matte(*this));
}

Matte & Matte::operator=(const Matte & rhs)
{
	if (this == &rhs)
		return *this;
	Material::operator=(rhs);
	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = nullptr;
	}
	if (rhs.ambient_brdf)
		ambient_brdf = rhs.ambient_brdf->clone();
	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = nullptr;
	}
	if (rhs.diffuse_brdf)
		diffuse_brdf = rhs.diffuse_brdf->clone();

	return *this;
}

RGBColor Matte::shade(ShadeRec & sr)
{
	Vector3D wo = -sr.ray.d;
	RGBColor L;
	return RGBColor();
}