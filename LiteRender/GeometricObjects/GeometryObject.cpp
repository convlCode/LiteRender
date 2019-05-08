#include "GeometryObject.h"
#include "../BasicTools/Constants.h"

GeometricObject::GeometricObject()
	:color{black}
{
}

GeometricObject::GeometricObject(const GeometricObject & obj)
	:color{obj.color}
{
}

GeometricObject & GeometricObject::operator=(const GeometricObject & rhs)
{
	if (this == &rhs)
		return *this;
	color = rhs.color;
	return *this;
}

GeometricObject::~GeometricObject()
{
}
