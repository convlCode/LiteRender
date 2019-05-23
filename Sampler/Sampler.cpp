#include <algorithm> //for random_shuffle
#include "Sampler.h"
#include "../BasicTools/Maths.h"

Sampler::Sampler()
	:	num_samples{1},num_sets{83},
		count{0},jump{0}
{
	samples.reserve(num_samples*num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const int num)
	:	num_samples{ num }, num_sets{ 83 },
		count{ 0 }, jump{ 0 }
{
	samples.reserve(num_samples*num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const int num, const int n_sets)
	:	num_samples{num},num_sets{num_sets},
		count{0},jump{0}
{
	samples.reserve(num_samples*num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const Sampler & s)
	:	num_samples{s.num_samples},num_sets{s.num_sets},
		samples{s.samples},shuffled_indices{s.shuffled_indices},
        count{s.count},jump{s.jump},hemisphere_samples(s.hemisphere_samples)
{
}

Sampler::~Sampler()
{
}

Sampler & Sampler::operator=(const Sampler & rhs)
{
	if (this == &rhs)
		return *this;
	num_samples = rhs.num_samples;
	num_sets = rhs.num_sets;
	samples = rhs.samples;
	shuffled_indices = rhs.shuffled_indices;
	count = rhs.count;
	jump = rhs.jump;
    hemisphere_samples	= rhs.hemisphere_samples;
	return *this;
}

void Sampler::shuffle_x_coordinates()
{
	for (int p = 0; p < num_sets; ++p) {
		for (int i = 0; i < num_samples - 1; ++i) {
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].x;
			samples[i + p * num_samples + 1].x = samples[target].x;
			samples[target].x = temp;
		}
	}
}

void Sampler::shuffle_y_coordinates()
{
	for (int p = 0; p < num_sets; ++p) {
		for (int i = 0; i < num_samples - 1; ++i) {
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].y;
			samples[i + p * num_samples + 1].y = samples[target].y;
			samples[target].y = temp;
		}
	}
}

void Sampler::setup_shuffled_indices()
{
	shuffled_indices.reserve(num_samples*num_sets);
	std::vector<int> indices;

	for (int j = 0; j < num_samples; j++)
		indices.push_back(j);
	for (int p = 0; p < num_sets; ++p) {
		std::random_shuffle(indices.begin(), indices.end());
		for (int j = 0; j < num_samples; ++j) {
			shuffled_indices.push_back(indices[j]);
		}
    }
}

void Sampler::map_samples_to_hemisphere(const float exp)
{
    int size = samples.size();
    hemisphere_samples.reserve(num_samples * num_sets);

    for (int j = 0; j < size; j++) {
        float cos_phi = cos(2.0 * PI * samples[j].x);
        float sin_phi = sin(2.0 * PI * samples[j].x);
        float cos_theta = pow((1.0 - samples[j].y), 1.0 / (exp + 1.0));
        float sin_theta = sqrt (1.0 - cos_theta * cos_theta);
        float pu = sin_theta * cos_phi;
        float pv = sin_theta * sin_phi;
        float pw = cos_theta;
        hemisphere_samples.push_back(Point3D(pu, pv, pw));
    }
}

void Sampler::map_samples_to_sphere()
{
    float r1, r2;
    float x, y, z;
    float r, phi;

    sphere_samples.reserve(num_samples * num_sets);

    for (int j = 0; j < num_samples * num_sets; j++) {
        r1 	= samples[j].x;
        r2 	= samples[j].y;
        z 	= 1.0f - 2.0f * r1;
        r 	= sqrt(1.0f - z * z);
        phi = static_cast<float>(TWO_PI) * r2;
        x 	= r * cos(phi);
        y 	= r * sin(phi);
        sphere_samples.push_back(Point3D(x, y, z));
    }
}

Point2D Sampler::sample_unit_square()
{
	if (count % num_samples == 0)  									// start of a new pixel
		jump = (rand_int() % num_sets) * num_samples;				// random index jump initialised to zero in constructor

    return (samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

Point3D Sampler::sample_hemisphere()
{
    if (count % num_samples == 0)  									// start of a new pixel
            jump = (rand_int() % num_sets) * num_samples;

    return (hemisphere_samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

Point3D Sampler::sample_sphere()
{
    if (count % num_samples == 0)  									// start of a new pixel
        jump = (rand_int() % num_sets) * num_samples;

    return (sphere_samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}
