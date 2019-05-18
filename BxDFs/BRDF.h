#ifndef BRDF_H
#define BRDF_H

#include "../BasicTools/RGBColor.h"
#include "../BasicTools/Vector3D.h"
#include "../BasicTools/ShadeRec.h"

class BRDF {
public:

	BRDF();
	BRDF(const BRDF& brdf);
	virtual	~BRDF();

	virtual BRDF* clone() const = 0;

	virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;

	virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;

	virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;

	virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;


protected:

	BRDF& operator= (const BRDF& rhs);
};

#endif
