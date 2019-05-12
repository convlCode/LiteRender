#include "MultiJittered.h"

MultiJittered::MultiJittered()
	: Sampler()
{
}

MultiJittered::MultiJittered(const int n_samples)
	:	Sampler(n_samples)
{
	generate_samples();
}

MultiJittered::MultiJittered(const int n_samples, const int m)
	: Sampler(n_samples, m)
{
	generate_samples();
}

MultiJittered::MultiJittered(const MultiJittered & mjs)
	:Sampler(mjs)
{
	generate_samples();
}

MultiJittered::~MultiJittered()
{
}

MultiJittered & MultiJittered::operator=(const MultiJittered & rhs)
{
	
}

MultiJittered * MultiJittered::clone() const
{
	return nullptr;
}

void MultiJittered::generate_samples()
{
}
