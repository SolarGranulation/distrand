/* distrand.h */
#ifndef DISTRAND_H
#define DISTRAND_H

#include <random>
#include "reference.h"

class DistRand : public Reference {
	OBJ_TYPE(DistRand,Reference);

	RealArray contents;
	
protected:
	static void _bind_methods();

public:
	void normal(int, float, float);

	float getvalue(int);

	DistRand();
};

#endif
