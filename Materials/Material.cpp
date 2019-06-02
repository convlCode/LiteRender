#include "Material.h"
#include "BasicTools/Constants.h"

Material::Material()
{
}

Material::Material(const Material & m)
{
}

Material::~Material()
{
}

Material & Material::operator=(const Material & rhs)
{
	return *this;
}

RGBColor Material::shade(ShadeRec & sr)
{
    return RGBColor(0.0f);
}

RGBColor Material::get_Le(ShadeRec &sr) const
{
    return black;
}

RGBColor Material::area_light_shade(ShadeRec &sr)
{
    return black;
}

RGBColor Material::path_shade(ShadeRec &sr)
{
    return black;
}
