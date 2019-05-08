#include "ShadeRec.h"

ShadeRec::ShadeRec(const World & wr)
	:hit_an_object{ false }, local_hit_point{ 0.0 },ray{},color{},normal{},t{0.0},w{wr}
{
}

ShadeRec::ShadeRec(const ShadeRec & sr)
	:hit_an_object{sr.hit_an_object},local_hit_point{sr.local_hit_point},
	ray{ sr.ray }, color{ sr.color }, normal{ sr.normal },t{sr.t},w{sr.w}
{
}

ShadeRec::~ShadeRec()
{
}
