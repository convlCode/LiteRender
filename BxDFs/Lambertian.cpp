#include "Lambertian.h"
#include "../BasicTools/Constants.h"
#include "Sampler/Sampler.h"

Lambertian::Lambertian()
    :	BRDF(),kd{0.0f},cd{0.0f},sampler_ptr{nullptr}
{
}

Lambertian::Lambertian(const Lambertian & lamb)
    :	BRDF(lamb),kd{lamb.kd},cd{lamb.cd},sampler_ptr{nullptr}
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

RGBColor Lambertian::rho(const ShadeRec & sr, const Vector3D & wo) const
{
    return kd * cd;
}

RGBColor Lambertian::sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi, float &pdf) const
{
    Vector3D w = sr.normal;
    Vector3D v = Vector3D(0.0034, 1, 0.0071) ^ w;
    v.normalize();
    Vector3D u = v ^ w;

    Point3D sp = sampler_ptr->sample_hemisphere();
    wi =  u * sp.x +  v * sp.y +  w * sp.z;
    wi.normalize();

    pdf = static_cast<float>(sr.normal * wi * invPI);
    float finvPI = static_cast<float>(invPI);
    return ( cd * kd * finvPI);
}

void Lambertian::set_sampler(Sampler *s_ptr)
{
    sampler_ptr = s_ptr;
    sampler_ptr->map_samples_to_hemisphere(1);
}
