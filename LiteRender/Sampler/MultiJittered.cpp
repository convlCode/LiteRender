#include "MultiJittered.h"
#include "../BasicTools/Maths.h"

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
	if (this == &rhs)
		return *this;
	Sampler::operator=(rhs);
	return *this;
}

MultiJittered * MultiJittered::clone() const
{
	return (new MultiJittered(*this));
}

void MultiJittered::generate_samples()
{
	// num_samples needs to be a perfect square
	int n = static_cast<int>(sqrt(static_cast<float>(num_samples)) );
	float subcell_width = 1.0f / static_cast<float>(num_samples);
	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the 
	// initial patterns
	Point2D fill_point;
	for (int j = 0; j < num_samples * num_sets; j++)
		samples.push_back(fill_point);
	// distribute points in the initial patterns
	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0.0f, subcell_width);
				samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0.0f, subcell_width);
			}
	// shuffle x coordinates
	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int k = rand_int(j, n - 1);
				float t = samples[i * n + j + p * num_samples].x;
				samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
				samples[i * n + k + p * num_samples].x = t;
			}
	// shuffle y coordinates
	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int k = rand_int(j, n - 1);
				float t = samples[j * n + i + p * num_samples].y;
				samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
				samples[k * n + i + p * num_samples].y = t;
			}
}
