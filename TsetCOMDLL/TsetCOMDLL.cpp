#include <objbase.h>
#include <iostream>
#include "MathCOM_h.h"
#include "MathCOM_i.c"

int main()
{
    //::system( "regsvr32.exe MathCOM.dll" );

    int ret = 0;
    do
    {
        HRESULT hr = ::CoInitializeEx( NULL, COINIT_MULTITHREADED );
        if (FAILED( hr )) {
            std::cout << "failed to `CoInitializeEx`" << std::endl;
            ret = hr;
            break;
        }

        IMathCOM* pMath = nullptr;
        hr = CoCreateInstance( CLSID_MathCOM, nullptr, CLSCTX_ALL, IID_IMathCOM, reinterpret_cast<LPVOID*>(&pMath) );
        // hr = CoCreateInstance( __uuidof(MathCOM), nullptr, CLSCTX_ALL, __uuidof(IMathCOM), reinterpret_cast<LPVOID*>(&pMath) );
        if (FAILED( hr )) {
            std::cout << "failed to `CoCreateInstance`, " << std::hex << hr << std::endl;
            ret = hr;
            break;
        }

        int ret = 0;
        hr = pMath->Sum( 1, 2, &ret );
        if (FAILED( hr )) {
            std::cout << "failed to `pMath->Sum( 1, 2, &ret )`, " << std::hex << hr << std::endl;
            ret = hr;
            break;
        }
        std::cout << "math->Sum(1, 2): " << ret << std::endl;

        float retf = 0.f;
        hr = pMath->Div( 1, 2, &retf );
        std::cout << "math->Div(1, 2): " << retf << std::endl;

        hr = pMath->Sqrt( 2, &retf );
        std::cout << "math->Sqrt(1, 2): " << retf << std::endl;
    } while (false);

    ::CoUninitialize();

    //::system( "regsvr32.exe /u MathCOM.dll" );
    return ret;
}
