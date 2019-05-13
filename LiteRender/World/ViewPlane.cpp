#include "ViewPlane.h"
#include "../Sampler/MultiJittered.h"

ViewPlane::ViewPlane()
	:hres{200},vres{100},gamma{0.0f},inv_gamma{0.0f},show_out_of_gamut{false}
{
}

ViewPlane::~ViewPlane()
{
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
		sampler_ptr = nullptr;
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
