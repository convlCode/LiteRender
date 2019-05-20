#ifndef SAMPLER_H
#define SAMPLER_H

#include <vector>
#include <cmath>

#include "../BasicTools/Point2D.h"
#include "../BasicTools/Point3D.h"

class Sampler {
public:

	Sampler();
	Sampler(const int num);
	Sampler(const int num, const int n_sets);
	Sampler(const Sampler& s);
	virtual ~Sampler();

	Sampler& operator= (const Sampler& rhs);
	 
	virtual Sampler* clone() const = 0;
	virtual void generate_samples() = 0;

	void set_num_sets(const int np);
	int get_num_samples();

	void shuffle_x_coordinates();
	void shuffle_y_coordinates();
	void setup_shuffled_indices();

    void map_samples_to_hemisphere(const float exp);

	Point2D	sample_unit_square();
    Point3D sample_hemisphere();

protected:

	int 					num_samples;     		// the number of sample points in a set
	int 					num_sets;				// the number of sample sets
	std::vector<Point2D>	samples;				// sample points on a unit square
	std::vector<int>		shuffled_indices;		// shuffled samples array indices
	unsigned long 			count;					// the current number of sample points used
	int 					jump;					// random index jump
    std::vector<Point3D> 	hemisphere_samples;
};

inline void Sampler::set_num_sets(const int np)
{
	num_sets = np;
}

inline int Sampler::get_num_samples(void)
{
	return num_samples;
}

#endif
