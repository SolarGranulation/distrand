/* IntNormal.h */
#ifndef INTNORMAL_H
#define INTNORMAL_H

#include "BaseNormal.h"

class IntNormal : public BaseNormal<int, IntArray> { // Inherits Reference from base class
	OBJ_TYPE(IntNormal,Reference);
	
	using BaseNormal<int, IntArray>::dr_boxmuller;
	int round(float);
	
protected:
	static void _bind_methods();
	
public:
// 	In order to work in gdscript it seems that these must be explicitly written.
	void normal(int mean, int deviation) {BaseNormal<int, IntArray>::normal(mean, deviation);};
	void generate(int count); // IntNormal has its own needs here
	int getvalue(int i) {return BaseNormal<int, IntArray>::getvalue(i);};
	int getnext() {return BaseNormal<int, IntArray>::getnext();};
	
	IntNormal(){};
};

#endif
