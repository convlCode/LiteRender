#include "Matte.h"
#include "../BasicTools/ShadeRec.h"
#include "../World/World.h"
#include <iostream>

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
    RGBColor L = ambient_brdf->rho(sr,wo) * sr.w.ambient_ptr->L(sr);
	size_t num_lights = sr.w.lights.size();
	for (size_t j = 0; j < num_lights; ++j) {
		Vector3D wi = sr.w.lights[j]->get_direction(sr);
		float ndotwi = static_cast<float>(sr.normal * wi);
		if (ndotwi > 0.0f) {
			L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi;
		}
	}
    return L;
}

RGBColor Matte::area_light_shade(ShadeRec &sr)
{
    Vector3D 	wo = -sr.ray.d;
    RGBColor 	L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    auto 		num_lights = sr.w.lights.size();
    for (decltype(num_lights) j = 0; j < num_lights; j++) {
        Vector3D 	wi = sr.w.lights[j]->get_direction(sr);
        float 		ndotwi = static_cast<float>(sr.normal * wi);
        if (ndotwi > 0.0f) {
            //bool in_shadow = false;
            L += (diffuse_brdf->f(sr, wo, wi)
                * sr.w.lights[j]->L(sr) * sr.w.lights[j]->G(sr) * ndotwi ) / sr.w.lights[j]->pdf(sr);
        }
    }

    return L;
}
