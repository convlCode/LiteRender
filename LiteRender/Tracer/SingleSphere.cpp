#include "SingleSphere.h"
#include "../BasicTools/ShadeRec.h"
#include "../World/World.h"

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
	if (world_ptr->sphere.hit(ray, t, sr)) {
		Vector3D tempColor = Vector3D(sr.normal.x + 1.0, sr.normal.y + 1.0, sr.normal.z + 1.0)*0.5;
		float r = static_cast<float>(tempColor.x);
		float g = static_cast<float>(tempColor.y);
		float b = static_cast<float>(tempColor.z);
		return RGBColor(r, g, b);
	}
	else
		return world_ptr->background_color;
}
