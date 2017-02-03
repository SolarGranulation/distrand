/* register_types.cpp */

#include "register_types.h"
#include "object_type_db.h"
#include "distrand.h"

void register_distrand_types() {
	ObjectTypeDB::register_type<DistRand>();
}

void unregister_distrand_types() {
	// Nil
}
