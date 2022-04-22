#pragma once
#include "math_interface.h"

class CMathDLL : public IMathDLL
{
public:
	virtual int Sum( int x, int y );
	virtual float Div( int numerator, int denominator );
	virtual float Sqrt( int x );
	virtual float Pow( int x, int y );
};
