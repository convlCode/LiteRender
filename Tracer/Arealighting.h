#ifndef AREALIGHTING_H
#define AREALIGHTING_H

#include "Tracer.h"

class AreaLighting : public Tracer
{
public:
    AreaLighting();
    AreaLighting(World* worldPtr);
    virtual	~ AreaLighting();

    virtual RGBColor trace_ray(const Ray ray, const int depth) const;
};

#endif // AREALIGHTING_H
