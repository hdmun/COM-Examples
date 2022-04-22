#pragma once
#include "resource.h"

// class __declspec(uuid("D74170BC-D924-4312-AAF3-3EB619F8C6CD")) MathCOM;

class ATL_NO_VTABLE CMathCOM
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CMathCOM, &CLSID_MathCOM>
	// , public IMathCOM,
	, public IDispatchImpl<IMathCOM, &IID_IMathCOM, &LIBID_mathcomlib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMathCOM() {}
	virtual ~CMathCOM() {}

DECLARE_REGISTRY_RESOURCEID( IDR_MathCOM )
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP( CMathCOM )
	COM_INTERFACE_ENTRY( IMathCOM )
	COM_INTERFACE_ENTRY( IDispatch )
END_COM_MAP()

public:
	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease() {}

	// STDMETHOD( raw_Sum )( int x, int y, int* pRet );
	// STDMETHOD( raw_Div )( int numerator, int denominator, float* pRet);
	STDMETHODIMP Sum( int x, int y, int* pRet );
	STDMETHODIMP Div( int numerator, int denominator, float* pRet);
	STDMETHODIMP Sqrt( int x, float* pRet );
	STDMETHODIMP Pow( int x, int y, float* pRet );

};

// https://docs.microsoft.com/ko-kr/cpp/atl/reference/object-map-macros?view=msvc-170
OBJECT_ENTRY_AUTO( CLSID_MathCOM, CMathCOM )
