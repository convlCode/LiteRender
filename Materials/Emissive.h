#ifndef EMISSIVE_H
#define EMISSIVE_H

#include "Material.h"

class Emissive : public Material
{
public:
    Emissive();
    Emissive(const Emissive& em);
    virtual ~Emissive();
    Material* clone() const;
    Emissive& operator=(const Emissive& rhs);

    void scale_radiance(const float l);
    void set_ce(const float c);
    void set_ce(const RGBColor& c);
    void set_ce(const float r,const float g,const float b);

    virtual RGBColor get_Le(ShadeRec& sr) const;
    virtual RGBColor area_light_shade(ShadeRec& sr);
    virtual RGBColor path_shade(ShadeRec& sr);

private:
    float		ls;
    RGBColor 	ce;
};

inline void Emissive::scale_radiance(const float l)
{
    ls = l;
}

inline void Emissive::set_ce(const float c)
{
    ce.r = c;   ce.g = c;   ce.b = c;
}

inline void Emissive::set_ce(const RGBColor &c)
{
    ce = c;
}

inline void Emissive::set_ce(const float r, const float g, const float b)
{
    ce.r = r;   ce.g = g;   ce.b = b;
}

#endif // EMISSIVE_H
