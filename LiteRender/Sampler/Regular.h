#ifndef __REGULAR__
#define __REGULAR__

#include "Sampler.h"

class Regular : public Sampler {
public:

	Regular();
	Regular(const int n_samples);
	Regular(const int n_samples, const int m);
	Regular(const Regular & reg);
	virtual ~Regular();

	Regular & operator= (const Regular & rhs);
	virtual Regular* clone() const;

private:
	virtual void generate_samples();
};

#endif

