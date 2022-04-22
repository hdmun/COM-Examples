#include "pch.h"
#include "MathCom.h"
#include <cmath>


// STDMETHODIMP CMathCOM::raw_Sum( int x, int y, int* pRet )
STDMETHODIMP CMathCOM::Sum( int x, int y, int* pRet )
{
	if (!pRet)
		return E_POINTER;

	*pRet = x + y;
	return S_OK;
}

// STDMETHODIMP CMathCOM::raw_Div( int numerator, int denominator, float* pRet )
STDMETHODIMP CMathCOM::Div( int numerator, int denominator, float* pRet )
{
	if (!pRet)
		return E_POINTER;

	*pRet = numerator / denominator;
	return S_OK;
}

STDMETHODIMP CMathCOM::Sqrt( int x, float* pRet )
{
	if (!pRet)
		return E_POINTER;

	*pRet = sqrt( x );
	return S_OK;
}

STDMETHODIMP CMathCOM::Pow( int x, int y, float* pRet )
{
	if (!pRet)
		return E_POINTER;

	*pRet =  pow( x, y );
	return S_OK;
}
