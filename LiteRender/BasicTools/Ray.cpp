#include "Ray.h"

Ray::Ray()
	:o{ 0.0 }, d{ 0.0,0.0,0.1 }
{
}

Ray::Ray(const Vector3D & _o, const Vector3D & _d)
	: o{ _o }, d{ _d }
{
}

Ray::Ray(const Ray & ray)
	: o{ ray.o }, d{ ray.d }
{
}

Ray::~Ray()
{
}

Ray & Ray::operator=(const Ray & ray)
{
	if (this == &ray)
		return *this;
	o = ray.o;
	d = ray.d;
	return *this;
}
