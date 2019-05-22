#include "Emissive.h"

Emissive::Emissive()
    :Material()
{
}

Emissive::Emissive(const Emissive &em)
    :Material(em)
{
}

Emissive::~Emissive()
{
}

Material *Emissive::clone() const
{
    return (new Emissive(*this));
}

Emissive &Emissive::operator=(const Emissive &rhs)
{
    if(this==&rhs)
        return (*this);
    Material::operator=(rhs);
    return (*this);
}

RGBColor Emissive::get_Le(ShadeRec &sr) const
{
    return (ls*ce);
}

RGBColor Emissive::area_light_shade(ShadeRec &sr)
{
    if((-sr.normal * sr.ray.d) > 0.0)
        return (ls*ce);
    else {
        return RGBColor(0.0f);
    }
}
