#ifndef RAY_CAST_H
#define RAY_CAST_H

#include "Tracer.h"

class RayCast : public Tracer {
public:

	RayCast();

	RayCast(World* _worldPtr);

	virtual ~RayCast();

	virtual RGBColor trace_ray(const Ray& ray) const;

	virtual RGBColor trace_ray(const Ray ray, const int depth) const;
};

#endif
