#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometryObject.h"
#include "Sampler/Sampler.h"

class Rectangle : public GeometricObject
{
public:
    Rectangle();
    Rectangle(const Rectangle& r);
    Rectangle(const Point3D& p, const Vector3D& va, const Vector3D& vb);
    Rectangle(const Point3D& p, const Vector3D& va, const Vector3D& vb, const Vector3D& nor);
    virtual ~Rectangle();

    virtual Rectangle* clone() const;
    Rectangle& operator= (const Rectangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

    virtual void set_sampler(Sampler* sampler);
    virtual Point3D sample();
    virtual Vector3D get_normal(const Point3D& p);
    virtual float pdf(ShadeRec& sr);

private:
    Point3D 		p0;   			// corner vertex
    Vector3D		a;				// side
    Vector3D		b;				// side
    double			a_len_squared;	// square of the length of side a
    double			b_len_squared;	// square of the length of side b
    Vector3D		normal;

    float			area;			// for rectangular lights
    float			inv_area;		// for rectangular lights
    Sampler*		sampler_ptr;	// for rectangular lights

    static const double kEpsilon;
};

#endif // RECTANGLE_H
