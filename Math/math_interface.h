#pragma once

#ifdef DLL_EXPORT
#define DLL_DECLSPEC  __declspec(dllexport)
#else
#define DLL_DECLSPEC  __declspec(dllimport)
#endif

class DLL_DECLSPEC IMathDLL
{
public:
	virtual int Sum( int x, int y ) = 0;
	virtual float Div( int numerator, int denominator ) = 0;
	virtual float Sqrt( int x ) = 0;
	virtual float Pow( int x, int y ) = 0;
};

DLL_DECLSPEC IMathDLL* CreateInstance();
