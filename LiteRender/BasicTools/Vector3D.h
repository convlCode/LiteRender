#ifndef __VECTOR_3D__
#define __VECTOR_3D__

class Vector3D
{
public:
	Vector3D();
	Vector3D(double a);										// constructor
	Vector3D(double _x, double _y, double _z);				// constructor
	Vector3D(const Vector3D& v);							// copy constructor
	//Vector3D(const Normal& n);								// constructs a vector from a Normal
	//Vector3D(const Point3D& p);								// constructs a vector from a point
	~Vector3D();

	Vector3D &operator=(const Vector3D &v);
	Vector3D operator+(const Vector3D &v) const;
	Vector3D operator-(const Vector3D &v) const;
	double operator*(const Vector3D &v) const;
	Vector3D operator*(const double s) const;
	Vector3D operator/(const double s) const;

	Vector3D operator-();
	Vector3D operator+=(const Vector3D &v) const;
	Vector3D operator-=(const Vector3D &v) const;

public:
	double x;
	double y;
	double z;
};

inline Vector3D Vector3D::operator-()
{
	return Vector3D(-x, -y, -z);
}

inline Vector3D Vector3D::operator+=(const Vector3D &v) const
{
	return Vector3D(x + v.x, y + v.y, z + v.z);
}

inline Vector3D Vector3D::operator-=(const Vector3D &v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z);
}

#endif