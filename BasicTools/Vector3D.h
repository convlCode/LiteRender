#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
	Vector3D();
	Vector3D(double a);										// constructor
	Vector3D(double _x, double _y, double _z);				// constructor
	Vector3D(const Vector3D& v);							// copy constructor
	//Vector3D(const Point3D& p);								// constructs a vector from a point
	~Vector3D();

	Vector3D &operator=(const Vector3D &v);
	Vector3D operator+(const Vector3D &v) const;
	Vector3D operator-(const Vector3D &v) const;
	double operator*(const Vector3D &v) const;
	Vector3D operator*(const double s) const;
	Vector3D operator/(const double s) const;

    Vector3D operator-() const;
	Vector3D operator+=(const Vector3D &v) const;
	Vector3D operator-=(const Vector3D &v) const;
	Vector3D operator^ (const Vector3D& v) const; //cross product

	void normalize();
    double length() const;
    double len_squared() const;

public:
	double x;
	double y;
	double z;
};

inline Vector3D Vector3D::operator-() const
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

inline Vector3D Vector3D::operator^(const Vector3D & v) const
{
    return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

inline double Vector3D::len_squared() const
{
    return (x * x + y * y + z * z);
}

#endif
