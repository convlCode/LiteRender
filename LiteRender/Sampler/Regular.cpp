#include "Regular.h"

Regular::Regular()
	:Sampler()
{
	generate_samples();
}

Regular::Regular(const int n_samples)
	:Sampler(n_samples)
{
	generate_samples();
}

Regular::Regular(const int n_samples, const int m)
	: Sampler(n_samples, m)
{
	generate_samples();
}

Regular::Regular(const Regular & reg)
	:Sampler(reg)
{
	generate_samples();
}

Regular::~Regular()
{
}

Regular & Regular::operator=(const Regular & rhs)
{
	if (this == &rhs)
		return *this;
	Sampler::operator=(rhs);
	return *this;
}

Regular * Regular::clone() const
{
	return (new Regular(*this));
}

void Regular::generate_samples()
{
	for (int p = 0; p < num_sets; ++p) {
		for (int j = 0; j < num_samples; ++j) {
			for (int k = 0; k < num_samples; ++k) {
				Point2D sp((j + 0.5f) / num_samples, (k + 0.5f) / num_samples);
				samples.push_back(sp);
			}
		}
	}
}
