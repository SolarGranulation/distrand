/* IntNormal.cpp */

#include "IntNormal.h"

void IntNormal::_bind_methods() {
	ObjectTypeDB::bind_method("normal",&IntNormal::normal);
// 	ObjectTypeDB::bind_method("skew",&BaseNormal::skew);
	ObjectTypeDB::bind_method("generate",&IntNormal::generate);
	ObjectTypeDB::bind_method("getvalue",&IntNormal::getvalue);
	ObjectTypeDB::bind_method("getnext",&IntNormal::getnext);
}

int IntNormal::round(float n) {
	// The purpose of the algorithm is to accurately round floating-point numbers.
	// C++11 has a builtin for this but I'm using C++98 here.
	// Would use C++11 but it doesn't play well with Java via Scons, for me.
	float t = n - floor(n);
	t *= 10;
	if(t > 4 && t < 5) {  // Then we need to look at the next digit!
		t = round(t); // Round the current value of t
	}
	// Implicit else
	if(t >= 5)
		return (int)(floor(n)+1);
	// Implicit else
	return (int)floor(n);	
}

void IntNormal::generate(int count) {
	if(sigma > 0) {
		// TODO Seed, if not using an idiom.

		contents.resize(0);
		for(int i=0; i<count; ++i) {
			contents.push_back(round(dr_boxmuller(mu, sigma)));
		}
	}
}
	
