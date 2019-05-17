#include "GeometryObject.h"
#include "../BasicTools/Constants.h"
#include "../Materials/Material.h"

GeometricObject::GeometricObject()
	:material_ptr{nullptr}
{
}

GeometricObject::GeometricObject(const GeometricObject & obj)
{
	if (obj.material_ptr) {
		material_ptr = obj.material_ptr->clone();
	}
	else{
		material_ptr = nullptr;
	}
}

GeometricObject::~GeometricObject()
{
	if (material_ptr) {
		delete material_ptr;
		material_ptr = nullptr;
	}
}

GeometricObject & GeometricObject::operator=(const GeometricObject & rhs)
{
	if (this == &rhs)
		return *this;
	if (material_ptr) {
		delete material_ptr;
		material_ptr = nullptr;
	}
	if (rhs.material_ptr)
		material_ptr = rhs.material_ptr->clone();
	return *this;
}

void GeometricObject::set_material(Material * m_ptr)
{
	if (material_ptr)
		delete material_ptr;
	material_ptr = m_ptr;
}
