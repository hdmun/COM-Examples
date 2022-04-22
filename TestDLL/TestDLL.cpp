#include <iostream>
#include "../Math/math_interface.h"

#pragma comment(lib, "../x64/Debug/Math.lib")

int main()
{
	IMathDLL* math = CreateInstance();
	std::cout << "math->Sum(1, 2): " << math->Sum( 1, 2 ) << std::endl;
	std::cout << "math->Div(1, 2): " << math->Div( 1, 2 ) << std::endl;
	std::cout << "math->Sqrt(1, 2): " << math->Sqrt( 2 ) << std::endl << std::endl;
	delete math;
	return 0;
}
