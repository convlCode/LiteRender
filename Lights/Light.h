#ifndef LIGHT_H
#define LIGHT_H

#include "../BasicTools/Vector3D.h"
#include "../BasicTools/RGBColor.h"
#include "../BasicTools/Ray.h"

class ShadeRec;

class Light
{
public:
	Light();
	Light(const Light& ls);
	virtual ~Light();

	virtual Light* clone() const = 0;
	Light& operator=(const Light& rhs);

	virtual Vector3D get_direction(ShadeRec& sr) = 0;
	virtual RGBColor L(ShadeRec& sr);
};

#endif
