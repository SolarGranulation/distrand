/* RealNormal.cpp */

#include "RealNormal.h"

void RealNormal::_bind_methods() {
	ObjectTypeDB::bind_method("normal",&RealNormal::normal);
// 	ObjectTypeDB::bind_method("skew",&BaseNormal::skew);
	ObjectTypeDB::bind_method("generate",&RealNormal::generate);
	ObjectTypeDB::bind_method("getvalue",&RealNormal::getvalue);
	ObjectTypeDB::bind_method("getnext",&RealNormal::getnext);
}

