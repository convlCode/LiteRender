#ifndef SPHERE_H
#define SPHERE_H

#include "GeometryObject.h"

class Sphere : public GeometricObject 
{
public:
	Sphere();
	Sphere(const Vector3D &ct, const double &r);
	Sphere(const Sphere &sp);
	virtual ~Sphere();

	Sphere &operator=(const Sphere &sp);
	virtual Sphere* clone() const;

	virtual bool hit(const Ray &ray, double &tmin, ShadeRec &sr) const;

	void set_center(const double x, const double y, const double z);
	void set_center(const Vector3D &c);
	void set_radius(const double r);
	
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

#endif
