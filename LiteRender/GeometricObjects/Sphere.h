#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "GeometryObject.h"

class Sphere : public GeometricObject 
{
public:
	Sphere();
	Sphere(const Vector3D &ct, const double &r);
	Sphere(const Sphere &sp);
	virtual ~Sphere();

	Sphere &operator=(const Sphere &sp);
	virtual bool hit(const Ray &ray, double &tmin, ShadeRec &sr) const;

	void set_center(const double x, const double y, const double z);
	void set_center(const Vector3D &c);
	void set_radius(const double r);
	void set_color(const float _r, const float _g, const float _b);
	
public:
	Vector3D center;
	double radius;
};

inline void Sphere::set_center(const double x, const double y, const double z)
{
	center.x = x;
	center.y = y;
	center.z = z;
}

inline void Sphere::set_center(const Vector3D & c)
{
	center = c;
}

inline void Sphere::set_radius(const double r)
{
	radius = r;
}

inline void Sphere::set_color(const float _r, const float _g, const float _b)
{
	color.r = _r;
	color.g = _g;
	color.b = _b;
}

#endif