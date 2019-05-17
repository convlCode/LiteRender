#include "Vector3D.h"
#include <cmath>


Vector3D::Vector3D()
	:x{0.0},y{0.0},z{0.0}
{
}

Vector3D::Vector3D(double a)
	:x{a},y{a},z{a}
{
}

Vector3D::Vector3D(double _x, double _y, double _z)
	:x{_x},y{_y},z{_z}
{
}

Vector3D::Vector3D(const Vector3D & v)
	:x{v.x},y{v.y},z{v.z}
{
}


Vector3D::~Vector3D()
{
}

Vector3D & Vector3D::operator=(const Vector3D & v)
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector3D Vector3D::operator+(const Vector3D & v) const
{
	return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D & v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z);
}

double Vector3D::operator*(const Vector3D & v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3D Vector3D::operator*(const double s) const
{
	return Vector3D(x*s, y*s, z*s);
}

Vector3D Vector3D::operator/(const double s) const
{
	return Vector3D(x / s, y / s, z / s);
}

void Vector3D::normalize()
{
	double length = sqrt(x*x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
}