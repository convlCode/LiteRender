#include "Tracer.h"

Tracer::Tracer()
	:world_ptr{nullptr}
{
}

Tracer::Tracer(World * wp)
	:world_ptr{wp}
{
}

Tracer::~Tracer()
{
	if (world_ptr) {
		//delete world_ptr;
		world_ptr = nullptr;
	}	
}

RGBColor Tracer::trace_ray(const Ray & ray) const
{
    return black;
}

RGBColor Tracer::trace_ray(const Ray ray, const int depth) const
{
    return black;
}
