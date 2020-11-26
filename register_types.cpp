/* register_types.cpp */

#include "register_types.h"
#include "RealNormal.h"
#include "IntNormal.h"

void register_gd_distrand_types() {
	ClassDB::register_class<RealNormal>();
	ClassDB::register_class<IntNormal>();
}

void unregister_gd_distrand_types() {
	// nothing
}
