#include "Sphere.h"
#include <cmath>
#include "../BasicTools/Point3D.h"

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

Sphere * Sphere::clone() const
{
	return (new Sphere(*this));
}

bool Sphere::hit(const Ray & ray, double & tmin, ShadeRec & sr) const
{
	double t;
	Vector3D temp = ray.o - center;
	double a = ray.d * ray.d;
	double b = temp * ray.d * 2;
	double c = temp * temp - radius * radius;
	double disc = b * b - a * c * 4;

	if (disc < 0.0)
		return (false);
	else {
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom; // smaller root

		if (t > 0) {
			tmin = t;
			sr.normal = (temp + ray.d * t) / radius;
			sr.local_hit_point = ray.o + ray.d * t;
			return (true);
		}

		t = (-b + e) / denom; // larger root

		if (t > 0) {
			tmin = t;
			sr.normal = (temp + ray.d * t) / radius;
			sr.local_hit_point = ray.o + ray.d * t;
			sr.hit_an_object = true;
			return (true);
		}
	}

	return false;
}
