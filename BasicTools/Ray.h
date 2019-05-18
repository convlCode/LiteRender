#ifndef RAY_H
#define RAY_H

#include "Point3D.h"
#include "Vector3D.h"

class Ray
{
public:
	Ray();
	Ray(const Point3D &_o, const Vector3D &_d);
	Ray(const Ray &ray);
	~Ray();

	Ray& operator=(const Ray &ray);
public:
	Point3D o;
	Vector3D d;
};

#endif // !_RAY_H_

