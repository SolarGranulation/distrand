/* distrand.h */
#ifndef DISTRAND_H
#define DISTRAND_H

#ifdef __ANDROID__
#include <stdlib.h>
//cmath???
#else
#include <cstdlib>
#include <cmath>
#endif
#include "reference.h"

class DistRand : public Reference {
	OBJ_TYPE(DistRand,Reference);

	int bookmark;
	RealArray contents;
	
	float dr_boxmuller(const float, const float);
	
protected:
	static void _bind_methods();

public:
	void normal(int, float, float);

	float getvalue(int);
	float getnext();

	DistRand();
};

#endif
