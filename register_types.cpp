/* register_types.cpp */

#include "register_types.h"
#include "object_type_db.h"
#include "RealNormal.h"
#include "IntNormal.h"

void register_distrand_types() {
	ObjectTypeDB::register_type<RealNormal>();
	ObjectTypeDB::register_type<IntNormal>();
}

void unregister_distrand_types() {
	// Nil
}
