/* RealNormal.h */
#ifndef REALNORMAL_H
#define REALNORMAL_H

#include "BaseNormal.h"

class RealNormal : public BaseNormal<float, RealArray> { // Inherits Reference from base class
	OBJ_TYPE(RealNormal,Reference);
	
	using BaseNormal<float, RealArray>::dr_boxmuller;
	
protected:
	static void _bind_methods();
	
public:
// 	In order to work in gdscript it seems that these must be explicitly written.
	void normal(float mean, float deviation) {BaseNormal<float, RealArray>::normal(mean, deviation);};
	void generate(int count) {BaseNormal<float, RealArray>::generate(count);};
	float getvalue(int i) {return BaseNormal<float, RealArray>::getvalue(i);};
	float getnext() {return BaseNormal<float, RealArray>::getnext();};
	
	RealNormal(){};
};

#endif
