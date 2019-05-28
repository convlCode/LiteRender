#ifndef SHADEREC_H
#define SHADEREC_H

#include "Vector3D.h"
#include "Ray.h"
#include "RGBColor.h"

class World;
class Material;

class ShadeRec {
public:
	ShadeRec(const World &wr);
	ShadeRec(const ShadeRec &sr);
	~ShadeRec();

public:
	bool hit_an_object;
	Point3D hit_point;
	Point3D local_hit_point;
	Ray ray;
	RGBColor color;
	Vector3D normal; //该点的法向量
	double t;
	World &w;
	Material*	material_ptr;
        int		depth; // recursion depth
};

#endif /* ifndef _SHADEREC_H_ */
