#include "PathTracer.h"
#include "World/World.h"
#include "Materials/Material.h"

PathTracer::PathTracer()
    :Tracer()
{

}

PathTracer::PathTracer(World *wp)
    :Tracer(wp)
{

}

RGBColor PathTracer::trace_ray(const Ray ray, const int depth) const
{
    if (depth > world_ptr->vp.max_depth)
        return (black);
    else {
        ShadeRec sr(world_ptr->hit_objects(ray));

        if (sr.hit_an_object) {
            sr.depth = depth;
            sr.ray = ray;

            return (sr.material_ptr->path_shade(sr));
        }
        else
            return (world_ptr->background_color);
    }
}
