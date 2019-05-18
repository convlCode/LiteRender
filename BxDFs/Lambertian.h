#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"

class Lambertian : public BRDF {
public:
	Lambertian();
	Lambertian(const Lambertian& lamb);
	~Lambertian();

	virtual Lambertian* clone() const;
	Lambertian& operator=(const Lambertian& rhs);

	virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;//use for ambient light

	void set_ka(const float k); //for ambient light
	void set_kd(const float k);
	void set_cd(const RGBColor& c);
	void set_cd(const float r, const float g, const float b);
	void set_cd(const float c);

public:
	float kd;
	RGBColor cd;                                                                               
};

inline void Lambertian::set_ka(const float k)
{
	kd = k;
}

inline void Lambertian::set_kd(const float k)
{
	kd = k;
}

inline void Lambertian::set_cd(const RGBColor & c)
{
	cd = c;
}

inline void Lambertian::set_cd(const float r, const float g, const float b)
{
	cd.r = r;	cd.g = g;	cd.b = b;
}

inline void Lambertian::set_cd(const float c)
{
	cd.r = c;	cd.g = c;	cd.b = c;
}
#endif
