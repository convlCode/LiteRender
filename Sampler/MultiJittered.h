#ifndef MULTI_JITTERED_H
#define MULTI_JITTERED_H

#include "Sampler.h"

class MultiJittered : public Sampler {
public:

	MultiJittered();
	MultiJittered(const int n_samples);
	MultiJittered(const int n_samples, const int m);
	MultiJittered(const MultiJittered& mjs);
	virtual ~MultiJittered();

	MultiJittered& operator= (const MultiJittered& rhs);
	virtual MultiJittered* clone() const;

private:
	virtual void generate_samples();
};

#endif

