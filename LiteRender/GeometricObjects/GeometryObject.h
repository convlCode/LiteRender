#ifndef _GEO_OBJECT_
#define _GEO_OBJECT_

#include "../BasicTools/Vector3D.h"
#include "../BasicTools/Ray.h"
#include "../BasicTools/RGBColor.h"
#include "../BasicTools/ShadeRec.h"

class GeometricObject {
public:
	GeometricObject();
	GeometricObject(const GeometricObject &obj);
	GeometricObject &operator=(const GeometricObject &rhs);
	virtual ~GeometricObject();

	virtual bool hit(const Ray &ray, double &t, ShadeRec &sr) const = 0;

	void set_color(const RGBColor &c);
	void set_color(const float r, const float g, const float b);
	RGBColor get_color(void);
public:
	RGBColor color;
};

inline void GeometricObject::set_color(const RGBColor & c)
{
	color = c;
}

inline void GeometricObject::set_color(const float r, const float g, const float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

inline RGBColor GeometricObject::get_color(void)
{
	return color;
}

#endif