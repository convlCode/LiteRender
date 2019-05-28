#ifndef MATERIAL_H
#define MATERIAL_H

#include "../BasicTools/RGBColor.h"
#include "../BasicTools/ShadeRec.h"

class Material {
public:

	Material();
	Material(const Material& m);
	virtual	~Material();

	virtual Material* clone() const = 0;
	virtual RGBColor shade(ShadeRec& sr);

    virtual RGBColor get_Le(ShadeRec& sr) const;
    virtual RGBColor area_light_shade(ShadeRec& sr);

protected:
	Material& operator= (const Material& rhs);
};

#endif
