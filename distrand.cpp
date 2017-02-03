/* distrand.cpp */

#include "distrand.h"

void DistRand::_bind_methods() {
	ObjectTypeDB::bind_method("normal",&DistRand::normal);
	ObjectTypeDB::bind_method("getvalue",&DistRand::getvalue);
}

void DistRand::normal(int elements, float mean, float deviation) {
	if(deviation > 0) {
		std::random_device rd;
		std::mt19937 gen(rd());

		std::normal_distribution<float> d(mean, deviation);

		for(int i=0; i<elements; ++i) {
			this->contents.push_back(d(gen));
		}
	}
}

float DistRand::getvalue(int i) {
	if(i < this->contents.size()) {
		return this->contents[i];
	}

	ERR_FAIL_COND_V(i >= this->contents.size(), 0.0)
}

DistRand::DistRand() {
	
}
