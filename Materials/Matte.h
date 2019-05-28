#ifndef MATTE_H
#define MATTE_H

#include "Material.h"
#include "../BxDFs/Lambertian.h"

class Matte : public Material {
public:

	Matte();
	Matte(const Matte& m);
	~Matte();

	virtual Material* clone() const;
	Matte& operator= (const Matte& rhs);

	void set_ka(const float k);
	void set_kd(const float k);
	void set_cd(const RGBColor c);
	void set_cd(const float r, const float g, const float b);
	void set_cd(const float c);

	virtual RGBColor shade(ShadeRec& sr);

    virtual RGBColor area_light_shade(ShadeRec& sr);//for areaLight
private:
	Lambertian*		ambient_brdf;
	Lambertian*		diffuse_brdf;
};

inline void Matte::set_ka(const float k)
{
	ambient_brdf->set_kd(k);
}

inline void Matte::set_kd(const float k)
{
	diffuse_brdf->set_kd(k);
}

inline void Matte::set_cd(const RGBColor c)
{
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

inline void Matte::set_cd(const float r, const float g, const float b)
{
	ambient_brdf->set_cd(r, g, b);
	diffuse_brdf->set_cd(r, g, b);
}

inline void Matte::set_cd(const float c)
{
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

#endif
