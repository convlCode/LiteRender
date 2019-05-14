#ifndef __MATTE__
#define __MATTE__

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

private:
	Lambertian*		ambient_brdf;
	Lambertian*		diffuse_brdf;
};

#endif