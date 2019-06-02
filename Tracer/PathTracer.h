#ifndef PATHTRACER_H
#define PATHTRACER_H

#include "Tracer.h"

class PathTracer : public Tracer
{
public:
    PathTracer();
    PathTracer(World* wp);
    virtual RGBColor trace_ray(const Ray ray, const int depth) const;
    //virtual RGBColor trace_ray(const Ray ray, double& tmin, const int depth) const;

};

#endif // PATHTRACER_H
