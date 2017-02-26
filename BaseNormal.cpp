/* BaseNormal.cpp */
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                         This file is part of:
//
//                               distrand
//
//                         Which is a module for
//                         use with Godot Engine
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// distrand
//
// Copyright © 2017 M T Harry Ayres
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal 
// in the Software without restriction, including without limitation the rights 
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
// copies of the Software, and to permit persons to whom the Software is 
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in 
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
// IN THE SOFTWARE.
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// GNU Terry Pratchett
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "BaseNormal.h"

template <typename T, class C> float BaseNormal<T, C>::dr_boxmuller(const T mu, const T sigma) { // mu = mean, sigma = standard deviation
	float epsilon = 0; // Hoping this will sort out any rounding error
	static float Zu, Zv; // The two deviates
	float U, V, s, R, Q; // Two random numbers (U & V), the sum of their cubes (s), the root of that (R) and Q which is the square root of the natural log of s multiplied by negative two.
	static bool generate, negative; // These two bools control function behaviour.
	
	int control = (rand());
	negative = ((control & 1<<0) == 1); // See if our new random int is odd
	// Seems biased.
	
	generate = !generate; // Generate two at a time, so only do it every other time.
	
	if(!generate) { // So if we're not generating a number this time
		if(negative) { // and we want a negative (half the time)
			return (float)mu - Zv * (float)sigma;
		} else { // or a positive (half the time)
			return (float)mu + Zv * (float)sigma;
		}
	}
	
	do {	// Generate the random values
		U = Math::randf(); // Godot idiom.
		V = Math::randf();
		s = (U*U + V*V); // This one is calculated here because it controls the loop
	} while(s <= epsilon || s >= 1);
	
	// These two are calculated outside the loop to save a miniscule bit of runtime
	R = sqrt(s);
	Q = sqrt(-2*log(s));
	
	// Calculate both variates. Common terms became variables to, again, save a miniscule bit of runtime
	// Cast to typename T
	Zu = (U/R)*Q;
	Zv = (V/R)*Q;
	
	if(negative) { // If we want a negative value, return here
		return (float)mu - Zu * (float)sigma;
	}
	
	return (float)mu + Zu * (float)sigma; // Otherwise return here
}

template <typename T, class C> void BaseNormal<T, C>::setparameters(T mean, T deviation) {
	if(deviation > 0) {
		mu = mean;
		sigma = deviation;
		contents.resize(0);
		bookmark = 0;
	}
}

template <typename T, class C> void BaseNormal<T, C>::generate(int quantity) {
	if(sigma > 0) {
		contents.resize(0);
		for(int i=0; i<quantity; ++i) {
			contents.push_back(dr_boxmuller(mu, sigma));
		}
		bookmark = 0;
	}
}

template <typename T, class C> T BaseNormal<T, C>::getvalue(int i) {
	if(i < contents.size()) {
		bookmark = i;
		return contents[bookmark];
	}

	ERR_FAIL_COND_V(i >= contents.size(), 0.0)
}

template <typename T, class C> T BaseNormal<T, C>::getnext() {
	int i = bookmark + 1;

	if(i < contents.size()) {
		bookmark = i;
		return contents[bookmark];
	}

	ERR_FAIL_COND_V("Out of bounds", 0.0)
}

template <typename T, class C> T BaseNormal<T, C>::getsingle() {
	return dr_boxmuller(mu, sigma);
}

template <typename T, class C> BaseNormal<T, C>::BaseNormal() {
	Math::randomize();
	bookmark = 0;
	mu = 0;
	sigma = 1;
}

// Explicitly create variates to avoid "undefined reference" errors.
template class BaseNormal<float, RealArray>;
template class BaseNormal<int, IntArray>;
