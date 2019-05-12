#ifndef __MATHS__
#define __MATHS__
#include <random>
#include "Constants.h"

inline int rand_int()
{
	static std::uniform_int_distribution<unsigned> u(0, 0x7fff);
	static std::default_random_engine e;
	return u(e);
}

inline float rand_float()
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<float> u(0, 1);
	return u(e);
}

#endif