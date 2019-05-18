#include "ViewPlane.h"
#include "../Sampler/MultiJittered.h"
#include "../Sampler/Regular.h"
ViewPlane::ViewPlane()
	:hres{ 200 }, vres{ 100 }, s{1.0f}, gamma{ 0.0f }, inv_gamma{ 0.0f }, 
	show_out_of_gamut{ false },sampler_ptr{ nullptr }, num_samples{ 1 }
{
}

ViewPlane::ViewPlane(const ViewPlane & vp)
	: hres{ vp.hres }, vres{ vp.vres },s{vp.s},gamma{vp.gamma},
	inv_gamma{vp.inv_gamma},show_out_of_gamut{vp.show_out_of_gamut},
    sampler_ptr{vp.sampler_ptr},num_samples{vp.num_samples}
{
}

ViewPlane::~ViewPlane()
{
	//if (sampler_ptr) {
		//delete sampler_ptr; //不注释会引发异常
		//sampler_ptr = nullptr;
	//}
}

ViewPlane & ViewPlane::operator=(const ViewPlane & rhs)
{
	if (this == &rhs)
		return (*this);

	hres = rhs.hres;
	vres = rhs.vres;
	s = rhs.s;
	num_samples = rhs.num_samples;
	gamma = rhs.gamma;
	inv_gamma = rhs.inv_gamma;
	show_out_of_gamut = rhs.show_out_of_gamut;
	sampler_ptr = rhs.sampler_ptr;
	return (*this);
}

void ViewPlane::set_samples(const int n)
{
	num_samples = n;
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = nullptr;
	}
	if (num_samples > 1)
		sampler_ptr = new MultiJittered(num_samples);
	else
		sampler_ptr = new Regular(1);
}

void ViewPlane::set_sampler(Sampler * sp)
{
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = nullptr;
	}
	num_samples = sp->get_num_samples();
	sampler_ptr = sp;
}
