/* NormalF.h */
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

class NormalF : public Reference {
	OBJ_TYPE(NormalF,Reference);

	int bookmark;
	float mu, sigma;
	RealArray contents;
	
	float dr_boxmuller(const float, const float);
	
protected:
	static void _bind_methods();

public:
	void normal(float, float);
	void skew(float);
	void generate(int);

	float getvalue(int);
	float getnext();

	NormalF();
};

#endif
