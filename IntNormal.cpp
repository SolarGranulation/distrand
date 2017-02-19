/* IntNormal.cpp */

#include "IntNormal.h"

void IntNormal::_bind_methods() {
	ObjectTypeDB::bind_method("normal",&IntNormal::normal);
// 	ObjectTypeDB::bind_method("skew",&BaseNormal::skew);
	ObjectTypeDB::bind_method("generate",&IntNormal::generate);
	ObjectTypeDB::bind_method("getvalue",&IntNormal::getvalue);
	ObjectTypeDB::bind_method("getnext",&IntNormal::getnext);
}

