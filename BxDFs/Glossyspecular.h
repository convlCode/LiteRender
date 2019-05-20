#ifndef GLOSSYSPECULAR_H
#define GLOSSYSPECULAR_H

#include "BRDF.h"
#include "Sampler/Sampler.h"

class GlossySpecular : public BRDF
{
public:
    GlossySpecular();
    GlossySpecular(const GlossySpecular& rhs);
    virtual ~GlossySpecular();
    virtual GlossySpecular* clone() const;
    GlossySpecular& operator=(const GlossySpecular& rhs);
    virtual RGBColor f(const ShadeRec& sr,const Vector3D& wo,const Vector3D& wi) const;
    virtual RGBColor sample_f(const ShadeRec& sr,const Vector3D& wo,Vector3D& wi,float& pdf) const;
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

    void set_ks(const float k);
    void set_exp(const float e);
    void set_cs(const RGBColor& c);
    void set_cs(const float r, const float g, const float b);
    void set_cs(const float c);
    void set_sampler(Sampler* sp, const float exp);
    void set_samples(const int num_samples, const float exp); 	// multi jittered sampling

private:
    float       ks;
    RGBColor    cs;
    float       exp;
    Sampler*    sampler_ptr;

};

inline void GlossySpecular::set_ks(const float k)
{
    ks = k;
}

inline void GlossySpecular::set_exp(const float e)
{
    exp = e;
}

inline void GlossySpecular::set_cs(const RGBColor &c)
{
    cs = c;
}

inline void GlossySpecular::set_cs(const float r, const float g, const float b)
{
    cs.r = r;   cs.g = g;   cs.b = b;
}

inline void GlossySpecular::set_cs(const float c)
{
    cs.r = c;   cs.g = c;   cs.b = c;
}

#endif // GLOSSYSPECULAR_H
