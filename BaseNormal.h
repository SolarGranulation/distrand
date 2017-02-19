/* BaseNormal.h */
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

template <typename T, class C>
class BaseNormal : public Reference {
	OBJ_TYPE(BaseNormal,Reference);

protected:
	int bookmark;
	T mu, sigma;
	C contents;
	
	float dr_boxmuller(const float, const float);

public:
	void normal(T mean, T deviation);
	void skew(float);
	void generate(int);

	T getvalue(int);
	T getnext();

	BaseNormal();
};

#endif
