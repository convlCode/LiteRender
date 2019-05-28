#include "Arealight.h"
#include "BasicTools/Constants.h"

AreaLight::AreaLight()
    :Light(),object_ptr{nullptr},material_ptr{nullptr}
{
}

AreaLight::AreaLight(const AreaLight &al)
    :Light(al)
{
    if(al.object_ptr)
        object_ptr = al.object_ptr->clone();
    else  object_ptr = nullptr;

    if(al.material_ptr)
        material_ptr = al.material_ptr->clone();
    else  material_ptr = nullptr;
}

AreaLight::~AreaLight()
{
 // no need to delete object_ptr and material_ptr,
 //because those pointers have been relesed in World's destructor.
    /*
    if (object_ptr) {
        delete object_ptr;
        object_ptr = nullptr;
    }
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }*/
}

AreaLight *AreaLight::clone() const
{
    return (new AreaLight(*this));
}

AreaLight &AreaLight::operator=(const AreaLight &rhs)
{
    if (this == &rhs)
        return (*this);
    Light::operator=(rhs);
    if (object_ptr) {
        delete object_ptr;
        object_ptr = nullptr;
    }
    if (rhs.object_ptr)
        object_ptr = rhs.object_ptr->clone();
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
    if (rhs.material_ptr)
        material_ptr = rhs.material_ptr->clone();
    return (*this);
}

Vector3D AreaLight::get_direction(ShadeRec &s)
{
    sample_point = object_ptr->sample();
    light_normal = object_ptr->get_normal(sample_point);
    wi=sample_point-s.hit_point;
    wi.normalize();

    return wi;
}

RGBColor AreaLight::L(ShadeRec &sr)
{
    double ndotd = (-light_normal) * wi;

    if( ndotd > 0.0)
        return (material_ptr->get_Le(sr));
    else {
        return black;
    }
}

float AreaLight::G(const ShadeRec &sr) const
{
    double ndotd = (-light_normal) * wi;
    double d2 = 1.0;
    d2 = sample_point.d_squared(sr.hit_point);

    return (static_cast<float>(ndotd / d2) );
}

float AreaLight::pdf(ShadeRec &sr)
{
    return (object_ptr->pdf(sr));
}
