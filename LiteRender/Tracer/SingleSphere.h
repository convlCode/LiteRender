#ifndef _SINGLE_SPHERE_H_
#define _SINGLE_SPHERE_H_

#include "Tracer.h"
//单球体跟踪器，不同的场景对象需要不同的跟踪计算过程，所以有不同版本的trace_ray实现
class SingleSphere : public Tracer 
{
public:
	SingleSphere();

	SingleSphere(World *_worldPtr);

	virtual ~SingleSphere(void);

	virtual RGBColor trace_ray(const Ray &ray) const;
};

#endif /* ifndef _SINGLE_SPHERE_H_ */
