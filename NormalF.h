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
class NormalF : public Reference {
	OBJ_TYPE(NormalF,Reference);

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

class RealNormal : /*public Reference, */public NormalF<float, RealArray> {
	OBJ_TYPE(RealNormal,Reference);
	
protected:
	static void _bind_methods();
	
	using NormalF<float, RealArray>::dr_boxmuller;
	
public:
// 	using NormalF<float, RealArray>::normal;
// 	using NormalF<float, RealArray>::skew;
// 	using NormalF<float, RealArray>::generate;
// 	using NormalF<float, RealArray>::getvalue;
// 	using NormalF<float, RealArray>::getnext;
	void normal(float mean, float deviation) {NormalF<float, RealArray>::normal(mean, deviation);};
	void skew(float factor) {NormalF<float, RealArray>::skew(factor);};
	void generate(int count) {NormalF<float, RealArray>::generate(count);};
	
	float getvalue(int i) {return NormalF<float, RealArray>::getvalue(i);};
	float getnext() {return NormalF<float, RealArray>::getnext();};
	
	RealNormal(){};
};

#endif
