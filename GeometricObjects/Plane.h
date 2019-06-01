#ifndef PLANE_H
#define PLANE_H

#include "GeometryObject.h"
//#include "BasicTools/Point3D.h"

class Plane : public GeometricObject
{
public:
    Plane();
    Plane(const Point3D & point, const Vector3D & normal);
    Plane(const Plane& plane);
    virtual ~Plane();

    virtual Plane* clone() const;
    Plane& operator= (const Plane& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    //virtual bool shadow_hit(const Ray& ray, double& tmin) const;

private:
    Point3D     a;
    Vector3D    n;
    //static const double kEpsilon;   // for shadows and secondary rays
};

#endif // PLAN_H
