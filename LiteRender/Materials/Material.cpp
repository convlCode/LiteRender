#include "Material.h"

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