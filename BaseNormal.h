/* BaseNormal.h */
#ifndef DISTRAND_H
#define DISTRAND_H

#ifdef __ANDROID__
#include <stdlib.h>
#else
#include <cstdlib>
#endif
#include "reference.h"

template <typename T, class C>
class BaseNormal : public Reference {
	OBJ_TYPE(BaseNormal,Reference);

protected:
	int bookmark;
	T mu, sigma;
	C contents;
	
	float dr_boxmuller(const T mu, const T sigma);

public:
	void normal(T mean, T deviation);
	void generate(int);

	T getvalue(int);
	T getnext();

	BaseNormal();
};

#endif
