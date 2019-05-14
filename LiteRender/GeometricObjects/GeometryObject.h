#ifndef _GEO_OBJECT_
#define _GEO_OBJECT_

#include "../BasicTools/Vector3D.h"
#include "../BasicTools/Ray.h"
#include "../BasicTools/RGBColor.h"
#include "../BasicTools/ShadeRec.h"
class Material;

class GeometricObject {
public:
	GeometricObject();
	GeometricObject(const GeometricObject &obj);
	virtual ~GeometricObject();

	GeometricObject &operator=(const GeometricObject &rhs);
	virtual GeometricObject* clone() const = 0;

	virtual bool hit(const Ray &ray, double &t, ShadeRec &sr) const = 0;

	virtual void set_material(Material* m_ptr);
	Material* get_material() const;

protected:
	Material* material_ptr;
};



inline Material * GeometricObject::get_material() const
{
	return material_ptr;
}

#endif