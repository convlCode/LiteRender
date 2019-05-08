#include "Sphere.h"

Sphere::Sphere()
	:GeometricObject(),center{0.0},radius{0.0}
{
}

Sphere::Sphere(const Vector3D & ct, const double & r)
	:GeometricObject(),center{ct},radius{r}
{
}

Sphere::Sphere(const Sphere & sp)
	:GeometricObject(sp),center{sp.center},radius{sp.radius}
{
}

Sphere::~Sphere()
{
}

Sphere & Sphere::operator=(const Sphere & sp)
{
	if (this == &sp)
		return *this;
	GeometricObject::operator=(sp);
	center = sp.center;
	radius = sp.radius;
	return *this;
}

bool Sphere::hit(const Ray & ray, double & tmin, ShadeRec & sr) const
{
	return false;
}
