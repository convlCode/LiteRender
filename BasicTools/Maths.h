#ifndef HEAD_MATHS
#define HEAD_MATHS
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

inline int rand_int(int low, int high)
{
	static std::uniform_int_distribution<unsigned> u(low, high);
	static std::default_random_engine e;
	return u(e);
}

inline float rand_float(float low, float high)
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<float> u(low, high);
	return u(e);
}

#endif
