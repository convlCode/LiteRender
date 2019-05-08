#ifndef _SHADEREC_H_
#define _SHADEREC_H_

#include "Vector3D.h"
#include "Ray.h"
#include "RGBColor.h"

class World;

class ShadeRec {
public:
	ShadeRec(const World &wr);
	ShadeRec(const ShadeRec &sr);
	~ShadeRec();

public:
	bool hit_an_object;
	Vector3D local_hit_point;
	Ray ray;
	RGBColor color;
	Vector3D normal; //该点的法向量
	double t;
	const World &w;
};

#endif /* ifndef _SHADEREC_H_ */