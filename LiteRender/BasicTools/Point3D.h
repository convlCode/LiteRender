#ifndef __POINT3D__
#define __POINT3D__

#include "Vector3D.h"

class Point3D {
public:
	Point3D();													
	Point3D(const double a);									
	Point3D(const double a, const double b, const double c);	
	Point3D(const Point3D& p);									
	~Point3D();													

	Point3D& operator= (const Point3D& p);
	Point3D operator- (void) const;
	Point3D operator* (const double a) const;

	Vector3D operator+(const Vector3D &v) const;
	Vector3D operator-(const Vector3D &v) const;
	Vector3D operator-(const Point3D &p) const; //used in Camera

	double d_squared(const Point3D& p) const;
	double distance(const Point3D& p) const;
public:
	double x;
	double y;
	double z;
};

inline Point3D Point3D::operator-(void) const
{
	return Point3D(-x, -y, -z);
}

inline Point3D Point3D::operator*(const double a) const
{
	return Point3D(x*a, y*a, z*a);
}

inline Vector3D Point3D::operator+(const Vector3D & v) const
{
	return Vector3D(x + v.x, y + v.y, z + v.z);
}

inline Vector3D Point3D::operator-(const Vector3D & v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z);
}

inline Vector3D Point3D::operator-(const Point3D & p) const
{
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

#endif