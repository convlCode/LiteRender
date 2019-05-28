#ifndef AREALIGHT_H
#define AREALIGHT_H

#include "Light.h"
#include "GeometricObjects/GeometryObject.h"
#include "Materials/Material.h"

class AreaLight : public Light
{
public:
    AreaLight();
    AreaLight(const AreaLight& al);
    virtual ~AreaLight();

    virtual AreaLight* clone() const;
    AreaLight& operator= (const AreaLight& rhs);

    void set_object(GeometricObject* obj_ptr);

    virtual Vector3D get_direction(ShadeRec& s);
    virtual RGBColor L(ShadeRec& sr);
    //virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

    virtual float G(const ShadeRec& sr) const;
    virtual float pdf(ShadeRec& sr);

    //virtual void set_cast_shadow(bool cs);
    //virtual bool get_cast_shadow(void);
private:
    GeometricObject* 	object_ptr;
    Material* 			material_ptr;	 // will be an emissive material
    Point3D				sample_point;
    Vector3D			light_normal;    // assigned in get_direction - which therefore can't be const for any light
    Vector3D			wi;			     // unit direction from hit point being shaded to sample point on light surface
};

inline void AreaLight::set_object(GeometricObject *obj_ptr)
{
    object_ptr = obj_ptr;
    material_ptr = obj_ptr->get_material();
}

#endif // AREALIGHT_H
