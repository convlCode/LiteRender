#include "SingleSphere.h"
#include "../BasicTools/ShadeRec.h"
SingleSphere::SingleSphere()
	:Tracer()
{
}

SingleSphere::SingleSphere(World * _worldPtr)
	:Tracer(_worldPtr)
{
}

SingleSphere::~SingleSphere(void)
{
}

RGBColor SingleSphere::trace_ray(const Ray & ray) const
{
	double t;
	ShadeRec sr(*world_ptr);
	if (world_ptr->sphere.hit(ray, t, sr))
		return (red);
	else
		return (blue);
}
