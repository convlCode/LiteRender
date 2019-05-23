#ifndef SPHERE_H
#define SPHERE_H

#include "GeometryObject.h"
#include "Sampler/Sampler.h"

class Sphere : public GeometricObject 
{
public:
	Sphere();
	Sphere(const Vector3D &ct, const double &r);
	Sphere(const Sphere &sp);
	virtual ~Sphere();

	Sphere &operator=(const Sphere &sp);
	virtual Sphere* clone() const;

	virtual bool hit(const Ray &ray, double &tmin, ShadeRec &sr) const;

	void set_center(const double x, const double y, const double z);
	void set_center(const Vector3D &c);
	void set_radius(const double r);

    // the following functions are used when the sphere is a light source
    void set_sampler(Sampler* sampler);
    virtual Point3D sample(void);
    virtual Vector3D get_normal(const Point3D& p);
    virtual float pdf(ShadeRec& sr);
	
public:
    Vector3D    center;
    double      radius;

    float       area;			// for spherical lights
    float		inv_area;		// for spherical lights
    Sampler*	sampler_ptr;	// for spherical lights
};

inline void Sphere::set_center(const double x, const double y, const double z)
{
	center.x = x;
	center.y = y;
	center.z = z;
}

inline void Sphere::set_center(const Vector3D & c)
{
	center = c;
}

inline void Sphere::set_radius(const double r)
{
	radius = r;
}

#endif
