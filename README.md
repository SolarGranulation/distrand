# distrand

**A Random Number Generation modules for users of [Godot Engine](http://godotengine.org/).**

## Purpose

The goal of the project is to provide a convenient and efficient tool for 
generating random numbers with non-uniform distribution, which may then be used 
in games either through GDScript or by other modules. As a C++ modules it offers
execution advantages over scripted solutions.

## Using distrand

### Types

Currently distrand exposes two object classes, RealNormal and IntNormal. Both 
create normal (or Gaussian) distributions of random numbers.

**RealNormal** generates random value floats and holds them in a RealArray.

**IntNormal** generates random value integers and holds them in an IntArray.

#### Public Methods ####

* setparameters
* generate
* getvalue
* getnext

**setparameters( _mean_ , _deviation_ )**

> Takes two values, type-matched to the variant (ints for IntNormal, floats for 
> RealNormal), and sets the parameters for the next set of numbers to be 
> generated if those parameters are valid. Erases any set of values previously 
> generated in the object instance.

**generate( _count_ )**

> Where _count_ is an integer. Generates _count_ random values according to the
> normal distribution defined by stored parameters (mean and deviation).

**getvalue( _i_ )**

> Where _i_ is an integer lesser than the _count_ last generated. Returns the 
> value of the random number in position _i_ of the internal array. RealNormal 
> returns a float while IntNormal returns an integer.

**getnext()**

> Starting at the first element, sequentially returns each value resultant from 
> the previous generation. If getvalue has been called it continues from there.

#### GDScript Instantiation ####

RealNormal and IntNormal objects may be created like other objects in GDScript:

`var foo=RealNormal.new()`

To define and generate the distribution:

`foo.normal(5.0, 1.5)`

`foo.generate(50000)`

To access the data:
`foo.getvalue(42)`

`foo.getnext()`

## Future features

* Single-value methods.
* Histogram-friendly data in Int* distributions, proving a count of each value.
* Heart-cut and dog-food subsets of normal distributions.
* Bi- and Multi-modal distributions.
* Weibull distributions.
