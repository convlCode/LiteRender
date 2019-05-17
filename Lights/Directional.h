#ifndef __DIRECTIONAL__
#define __DIRECTIONAL__

#include "Light.h"

class Directional : public Light
{
public:
	Directional();
	Directional(const Directional& dl);
	virtual ~Directional();

	virtual Light* clone() const;
	Directional& operator=(const Directional& rhs);

	virtual RGBColor L(ShadeRec& sr);

	void scale_radiance(const float b);
	void set_color(const float c);
	void set_color(const RGBColor& c);
	void set_color(const float r, const float g, const float b);
	void set_direction(Vector3D d);
	void set_direction(float dx, float dy, float dz);
	virtual Vector3D get_direction(ShadeRec& sr);
private:
	float ls;
	RGBColor color;
	Vector3D dir;
};

inline void Directional::scale_radiance(const float b)
{
	ls = b;
}

inline void Directional::set_color(const float c)
{
	color.r = c;	color.g = c;	color.b = c;
}

inline void Directional::set_color(const RGBColor & c)
{
	color = c;
}

inline void Directional::set_color(const float r, const float g, const float b)
{
	color.r = r;	color.g = g;	color.b = b;
}

inline void Directional::set_direction(Vector3D d)
{
	dir = d;
	dir.normalize();
}

inline void Directional::set_direction(float dx, float dy, float dz)
{
	dir.x = dx;	dir.y = dy;	dir.z = dz;
	dir.normalize();
}

inline Vector3D Directional::get_direction(ShadeRec & sr)
{
	return dir;
}

#endif
