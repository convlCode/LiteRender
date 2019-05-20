#include "Ambient.h"

Ambient::Ambient()
    :Light(),ls{1.0f},color{1.0f}
{
}

Ambient::Ambient(const Ambient &a)
    :Light(a),ls{a.ls},color{a.color}
{
}

Ambient::~Ambient()
{
}

Light *Ambient::clone() const
{
    return (new Ambient(*this));
}

Ambient &Ambient::operator=(const Ambient &rhs)
{
    if(this==&rhs)
        return *this;
    Light::operator=(rhs);
    ls=rhs.ls;
    color = rhs.color;
    return *this;
}

Vector3D Ambient::get_direction(ShadeRec &s)
{
    return (Vector3D(0.0));
}

RGBColor Ambient::L(ShadeRec &s)
{
    return (ls * color);
}


