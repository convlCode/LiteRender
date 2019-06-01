#include "Plane.h"
#include "BasicTools/Constants.h"
Plane::Plane()
    :GeometricObject(),a{0.0},n{0,1,0}
{

}

Plane::Plane(const Point3D &point, const Vector3D &normal)
    :GeometricObject(),a{point},n{normal}
{
    n.normalize();
}

Plane::Plane(const Plane &plane)
    :GeometricObject(),a{plane.a},n{plane.n}
{

}

Plane::~Plane()
{

}

Plane *Plane::clone() const
{
    return (new Plane(*this));
}

Plane &Plane::operator=(const Plane &rhs)
{
    if(this==&rhs)
        return (*this);
    GeometricObject::operator=(rhs);
    a=rhs.a;
    n=rhs.n;

    return (*this);
}

bool Plane::hit(const Ray &ray, double &tmin, ShadeRec &sr) const
{
    double t = (a - ray.o) * n / (ray.d * n);

    if (t > kEpsilon) {
        tmin = t;
        sr.normal = n;
        sr.local_hit_point = ray.o +  ray.d*t;

        return true;
    }

    return false;
}
