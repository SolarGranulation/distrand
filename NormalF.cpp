/* NormalF.cpp */

#include "NormalF.h"

void NormalF::_bind_methods() {
	ObjectTypeDB::bind_method("normal",&NormalF::normal);
// 	ObjectTypeDB::bind_method("skew",&NormalF::skew);
	ObjectTypeDB::bind_method("generate",&NormalF::generate);
	ObjectTypeDB::bind_method("getvalue",&NormalF::getvalue);
	ObjectTypeDB::bind_method("getnext",&NormalF::getnext);
}

float NormalF::dr_boxmuller(const float mu=0.0, const float sigma=1.0) { // mu = mean, sigma = standard deviation
	float epsilon = (float)0; // Hoping this will sort out any rounding error
	static float Zu, Zv; // The two deviates
	float U, V, s, R, Q; // Two random numbers (U & V), the sum of their cubes (s), the root of that (R) and, well, R.
	static bool generate, negative; // These two bools control function behaviour.
	
	int control = (rand());
	negative = (bool)control & 1<<0; // See if our new random int is odd
	
	generate = !generate; // Generate two at a time, so only do it every other time.
	
	if(!generate) { // So if we're not generating a number this time
		if(negative) { // and we want a negative (half the time)
			return 0 - Zv * sigma + mu;
		} else { // or a positive (half the time)
			return Zv * sigma + mu;
		}
	}
	
	do {	// Generate the random values
		U = rand() * (1.0 / RAND_MAX); // May replace these with a godot-idiom if such exists
		V = rand() * (1.0 / RAND_MAX);
		s = (U*U + V*V); // This one is calculated here because it controls the loop
	} while(s <= epsilon || s >= 1);
	
	// These two are calculated outside the loop to save a miniscule bit of runtime
	R = sqrt(s);
	Q = sqrt(-2*log(s));
	
	// Calculate both variates. Common terms became variables to, again, save a miniscule bit of runtime
	Zu = (U/R)*Q;
	Zv = (V/R)*Q;
	
	if(negative) { // If we want a negative value, return here
		return 0 - Zu * sigma + mu;
	}
	
	return Zu * sigma + mu; // Otherwise return here
}

void NormalF::normal(float mean, float deviation) {
	if(deviation > 0) {
		mu = mean;
		sigma = deviation;
		contents.resize(0);
	}
}

void NormalF::skew(float factor) {
	// TODO
}

void NormalF::generate(int quantity) {
	if(sigma > 0) {
		// TODO Seed, if not using an idiom.

		contents.resize(0);
		for(int i=0; i<quantity; ++i) {
			contents.push_back(dr_boxmuller(mu, sigma));
		}
	}
}

float NormalF::getvalue(int i) {
	if(i < contents.size()) {
		bookmark = i;
		return contents[bookmark];
	}

	ERR_FAIL_COND_V(i >= contents.size(), 0.0)
}

float NormalF::getnext() {
	int i = bookmark + 1;

	if(i < contents.size()) {
		bookmark = i;
		return contents[bookmark];
	}

	ERR_FAIL_COND_V("Out of bounds", 0.0)
}

NormalF::NormalF() {
	
}
