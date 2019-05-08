#ifndef __TRACER__
#define __TRACER__

#include "../BasicTools/Constants.h"
#include "../BasicTools/RGBColor.h"
#include "../BasicTools/Ray.h"
#include "../World/World.h"

class Tracer
{
public:
	Tracer();
	Tracer(World* wp);
	virtual ~Tracer();

	virtual RGBColor trace_ray(const Ray &ray) const;
public:
	World* world_ptr;
};

#endif
