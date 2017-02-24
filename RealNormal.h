/* RealNormal.h */
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

#ifndef REALNORMAL_H
#define REALNORMAL_H

#include "BaseNormal.h"

class RealNormal : public BaseNormal<float, RealArray> { // Inherits Reference from base class
	OBJ_TYPE(RealNormal,Reference);
	
	using BaseNormal<float, RealArray>::dr_boxmuller;
	
protected:
	static void _bind_methods();
	
public:
// 	In order to work in gdscript it seems that these must be explicitly written.
	void setparameters(float mean, float deviation) {BaseNormal<float, RealArray>::setparameters(mean, deviation);};
	void generate(int count) {BaseNormal<float, RealArray>::generate(count);};
	float getvalue(int i) {return BaseNormal<float, RealArray>::getvalue(i);};
	float getnext() {return BaseNormal<float, RealArray>::getnext();};
	float getsingle() {return BaseNormal<float, RealArray>::getsingle();};
	
	RealNormal() : BaseNormal() {};
};

#endif
