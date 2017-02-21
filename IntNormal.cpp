/* IntNormal.cpp */
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

#include "IntNormal.h"

void IntNormal::_bind_methods() {
	ObjectTypeDB::bind_method("normal",&IntNormal::normal);
// 	ObjectTypeDB::bind_method("skew",&BaseNormal::skew);
	ObjectTypeDB::bind_method("generate",&IntNormal::generate);
	ObjectTypeDB::bind_method("getvalue",&IntNormal::getvalue);
	ObjectTypeDB::bind_method("getnext",&IntNormal::getnext);
}

int IntNormal::round(float n) {
	// The purpose of the algorithm is to accurately round floating-point numbers.
	// C++11 has a builtin for this but I'm using C++98 here.
	// Would use C++11 but it doesn't play well with Java via Scons, for me.
	
	if(n < 0) // If n is negative then flip the sign, recurse, then flip again and return.
		return -round(-n);
	// Implicit else
	
	float t = n - floor(n);
	t *= 10;
	if(t > 4 && t < 5) {  // Then we need to look at the next digit!
		t = round(t); // Round the current value of t
	}
	// Implicit else
	if(t >= 5)
		return (int)(floor(n)+1);
	// Implicit else
	return (int)floor(n);	
}

void IntNormal::generate(int count) {
	if(sigma > 0) {
		contents.resize(0);
		for(int i=0; i<count; ++i) {
			contents.push_back(round(dr_boxmuller(mu, sigma))); // Rounding the boxmuller result.
		}
	}
}
	
