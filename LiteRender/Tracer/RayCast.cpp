#include "RayCast.h"
#include "../World/World.h"
#include "../BasicTools/ShadeRec.h"

RayCast::RayCast()
	:Tracer()
{
}

RayCast::RayCast(World * _worldPtr)
	:Tracer(_worldPtr)
{
}

RayCast::~RayCast()
{
}

RGBColor RayCast::trace_ray(const Ray & ray) const
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

RGBColor RayCast::trace_ray(const Ray ray, const int depth) const
{
	return RGBColor();
}
