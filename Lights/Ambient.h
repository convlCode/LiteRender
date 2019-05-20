#ifndef AMBIENT_H
#define AMBIENT_H
#include "Light.h"

class Ambient : public Light
{
public:
    Ambient();
    Ambient(const Ambient& a);
    virtual ~Ambient();
    virtual Light* clone() const;
    Ambient& operator=(const Ambient& rhs);
    void scale_radiance(const float b);
    void set_color(const float c);
    void set_color(const RGBColor& c);
    void set_color(const float r,const float g,const float b);
    virtual Vector3D get_direction(ShadeRec &s);
    virtual RGBColor L(ShadeRec &s);
private:
    float ls;
    RGBColor color;
};

inline void Ambient::scale_radiance(const float b)
{
    ls = b;
}

inline void Ambient::set_color(const float c)
{
    color.r=c;  color.g=c;  color.b=c;
}

inline void Ambient::set_color(const RGBColor &c)
{
    color=c;
}

inline void Ambient::set_color(const float r, const float g, const float b)
{
    color.r=r;  color.g=g;  color.b=b;
}

#endif // AMBIENT_H
