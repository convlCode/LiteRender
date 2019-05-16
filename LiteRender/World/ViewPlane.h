#ifndef _VIEWPLANE_H_
#define _VIEWPLANE_H_

#include "../Sampler/Sampler.h"

class ViewPlane
{
public:
	ViewPlane();
	ViewPlane(const ViewPlane& vp);
	~ViewPlane();
	ViewPlane& operator= (const ViewPlane& rhs);
	void set_hres(const int h);
	void set_vres(const int v);
	void set_pixel_size(const float size);
	void set_gamma(const float g);
	void set_gamma_display(const bool show);
	void set_samples(const int n);
	void set_sampler(Sampler* sp);
public:
	int hres;
	int vres;
	float s;
	float gamma;
	float inv_gamma;
	bool show_out_of_gamut;
	Sampler* sampler_ptr;
	int num_samples;
};

inline void ViewPlane::set_hres(const int h)
{
	hres = h;
}

inline void ViewPlane::set_vres(const int v)
{
	vres = v;
}

inline void ViewPlane::set_pixel_size(const float size)
{
	s = size;
}

inline void ViewPlane::set_gamma(const float g)
{
	gamma = g;
	inv_gamma = 1.0f / g;
}

inline void ViewPlane::set_gamma_display(const bool show)
{
	show_out_of_gamut = show;
}

#endif // !_VIEWPLANE_H_
