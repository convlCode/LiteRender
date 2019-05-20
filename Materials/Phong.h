#ifndef PHONG_H
#define PHONG_H

#include "Materials/Material.h"
#include "BxDFs/Lambertian.h"
#include "BxDFs/Glossyspecular.h"

class Phong : public Material
{
public:
    Phong();
    Phong(const Phong& m);
    ~Phong();

    virtual Material* clone() const;
    Phong& operator= (const Phong& rhs);

    void set_ka(const float k);

    void set_kd(const float k);

    void set_ks(const float k);
    void set_exp (const float exp);

    void set_cd(const RGBColor c);
    void set_cd(const float r, const float g, const float b);
    void set_cd(const float c);

    virtual RGBColor shade(ShadeRec& sr);

private:
    Lambertian*		ambient_brdf;
    Lambertian*		diffuse_brdf;
    GlossySpecular*	specular_brdf;
};

inline void Phong::set_ka(const float k)
{
    ambient_brdf->set_ka(k);
}

inline void Phong::set_kd(const float k)
{
    diffuse_brdf->set_kd(k);
}

inline void Phong::set_ks(const float k)
{
    specular_brdf->set_ks(k);
}

inline void Phong::set_exp(const float exp)
{
    specular_brdf->set_exp(exp);
}

inline void Phong::set_cd(const RGBColor c)
{
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

inline void Phong::set_cd(const float r, const float g, const float b)
{
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

inline void Phong::set_cd(const float c)
{
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

#endif // PHONG_H
