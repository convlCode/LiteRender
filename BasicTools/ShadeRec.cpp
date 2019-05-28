#include "ShadeRec.h"

ShadeRec::ShadeRec(const World & wr)
	:hit_an_object{ false }, hit_point{0.0}, local_hit_point{ 0.0 }, ray{},
    color{}, normal{}, t{ 0.0 }, w{ const_cast<World&>(wr) },
    material_ptr{ nullptr },depth{0}
{
}

ShadeRec::ShadeRec(const ShadeRec & sr)
	: hit_an_object{ sr.hit_an_object }, hit_point{sr.hit_point}, 
	local_hit_point{ sr.local_hit_point }, ray{ sr.ray },
	color{ sr.color }, normal{ sr.normal }, t{ sr.t }, 
    w{ sr.w }, material_ptr{ sr.material_ptr },depth{sr.depth}
{
}

ShadeRec::~ShadeRec()
{
}
