#ifndef _RAY_H_
#define _RAY_H_

#include "Vector3D.h"

class Ray
{
public:
	Ray();
	Ray(const Vector3D &_o, const Vector3D &_d);
	Ray(const Ray &ray);
	~Ray();

	Ray& operator=(const Ray &ray);
public:
	Vector3D o;
	Vector3D d;
};

#endif // !_RAY_H_

