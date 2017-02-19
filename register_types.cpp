/* register_types.cpp */

#include "register_types.h"
#include "object_type_db.h"
#include "NormalF.h" // Should rename this

void register_distrand_types() {
	ObjectTypeDB::register_type<RealNormal>();
}

void unregister_distrand_types() {
	// Nil
}
