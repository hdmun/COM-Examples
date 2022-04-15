#pragma once

#ifdef DLL_EXPORT
#define DLL_DECLSPEC  __declspec(dllexport)
#else
#define DLL_DECLSPEC  __declspec(dllimport)
#endif

class DLL_DECLSPEC CMathDLL
{
public:
	int Sum( int x, int y );
	float Div( int numerator, int denominator );
	float Sqrt( int x );
	float Pow( int x, int y );
};

DLL_DECLSPEC CMathDLL* CreateInstance();
