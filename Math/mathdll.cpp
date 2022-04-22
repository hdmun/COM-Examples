#include "pch.h"
#include "MathDLL.h"
#include <cmath>

int CMathDLL::Sum( int x, int y )
{
	return x + y;
}

float CMathDLL::Div( int numerator, int denominator )
{
	return numerator / denominator;
}

float CMathDLL::Sqrt( int x )
{
	return sqrt( x );
}

float CMathDLL::Pow( int x, int y )
{
	return pow( x, y );
}


IMathDLL* CreateInstance()
{
	return new CMathDLL;
}
