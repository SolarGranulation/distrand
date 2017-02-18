/* register_types.cpp */

#include "register_types.h"
#include "object_type_db.h"
#include "NormalF.h"

void register_distrand_types() {
	ObjectTypeDB::register_type<RealNormal>();
}

void unregister_distrand_types() {
	// Nil
}
