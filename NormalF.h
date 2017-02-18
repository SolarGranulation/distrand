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

template <typename T, class C>
class NormalF /*: public Reference*/ {
	//OBJ_TYPE(NormalF,Reference);

protected:
	int bookmark;
	T mu, sigma;
	C contents;
	
	float dr_boxmuller(const float, const float);
	
// protected:
// 	static void _bind_methods();

public:
	void normal(T mean, T deviation);
	void skew(float);
	void generate(int);

	T getvalue(int);
	T getnext();

	NormalF();
};

class RealNormal : public Reference, public NormalF<float, RealArray> {
	OBJ_TYPE(RealNormal,Reference);
	
protected:
	static void _bind_methods();
};

#endif
