// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"
#include "resource.h"

class CMathCOMModule : public ATL::CAtlDllModuleT< CMathCOMModule >
{
public:
    DECLARE_LIBID( LIBID_mathcomlib )
    DECLARE_REGISTRY_APPID_RESOURCEID( IDR_MathCOMDLL, "{49793CD2-51B0-410B-AC7B-12700C372231}" )
};

CMathCOMModule _Module;

STDAPI DllCanUnloadNow()
{
	HRESULT hr = _Module.DllCanUnloadNow();
	return hr;
}

STDAPI DllGetClassObject( _In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv )
{
    HRESULT hr = _Module.DllGetClassObject( rclsid, riid, ppv );
	return hr;
}

STDAPI DllRegisterServer()
{
	HRESULT hr = _Module.DllRegisterServer();
	return hr;
}

STDAPI DllUnregisterServer()
{
	HRESULT hr = _Module.DllUnregisterServer();
	return hr;
}


// DllInstall - Adds/Removes entries to the system registry per user per machine.
STDAPI DllInstall( BOOL bInstall, _In_opt_  LPCWSTR pszCmdLine )
{
	HRESULT hr = E_FAIL;
	static const wchar_t szUserSwitch[] = L"user";

	if (pszCmdLine != nullptr)
	{
		if (_wcsnicmp( pszCmdLine, szUserSwitch, _countof( szUserSwitch ) ) == 0)
		{
			ATL::AtlSetPerUserRegistration( true );
		}
	}

	if (bInstall)
	{
		hr = DllRegisterServer();
		if (FAILED( hr ))
		{
			DllUnregisterServer();
		}
	}
	else
	{
		hr = DllUnregisterServer();
	}

	return hr;
}


#include "MathCom.h"
extern "C"
BOOL APIENTRY DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
	// CMathCOM a;
	return _Module.DllMain( dwReason, lpReserved );
}
