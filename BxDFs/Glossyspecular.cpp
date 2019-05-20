#include "Glossyspecular.h"
#include "Sampler/MultiJittered.h"
#include "BasicTools/Constants.h"

GlossySpecular::GlossySpecular()
    :BRDF(),ks{0.0f},cs{1.0f},sampler_ptr{nullptr}
{

}

GlossySpecular::GlossySpecular(const GlossySpecular &rhs)
    :BRDF(),ks{rhs.ks},cs{rhs.cs},sampler_ptr{rhs.sampler_ptr}
{
}

GlossySpecular::~GlossySpecular()
{
}

GlossySpecular *GlossySpecular::clone() const
{
    return (new GlossySpecular(*this));
}

GlossySpecular &GlossySpecular::operator=(const GlossySpecular &rhs)
{
    if (this == &rhs)
        return (*this);
    BRDF::operator=(rhs);
    ks = rhs.ks;
    cs = rhs.cs;
    return *this;
}

RGBColor GlossySpecular::f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const
{
    RGBColor 	L;
    double 		ndotwi = sr.normal * wi;
    Vector3D 	r(-wi + sr.normal* 2.0 * ndotwi); // mirror reflection direction
    float 		rdotwo = static_cast<float>(r * wo);

    if (rdotwo > 0.0f)
        L = ks * cs * pow(rdotwo, exp);
    return (L);
}

RGBColor GlossySpecular::sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi, float &pdf) const
{
    double ndotwo = sr.normal * wo;
    Vector3D r = -wo + sr.normal * 2.0 * ndotwo;     // direction of mirror reflection

    Vector3D w = r;
    Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
    u.normalize();
    Vector3D v = u ^ w;

    Point3D sp = sampler_ptr->sample_hemisphere();
    wi =  u * sp.x  + v * sp.y  + w * sp.z;			// reflected ray direction

        if (sr.normal * wi < 0.0) 						// reflected ray is below tangent plane
            wi = - u * sp.x - v * sp.y  + w * sp.z;

        float phong_lobe = static_cast<float>(pow(r * wi, exp));
        pdf = phong_lobe * static_cast<float>(sr.normal * wi);

        return ( cs * ks * phong_lobe);
}

RGBColor GlossySpecular::rho(const ShadeRec &sr, const Vector3D &wo) const
{
    return black;
}

void GlossySpecular::set_sampler(Sampler *sp, const float exp)
{
    sampler_ptr = sp;
    sampler_ptr->map_samples_to_hemisphere(exp);
}

void GlossySpecular::set_samples(const int num_samples, const float exp)
{
    sampler_ptr = new MultiJittered(num_samples);
    sampler_ptr->map_samples_to_hemisphere(exp);
}
