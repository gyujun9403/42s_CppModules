#include <iostream>
#include "whatever.hpp"
#include "TestClass.hpp"

int main()
{
	int int1 = 10, int2 = 12;
	int int3 = 15, int4 = 19;
	double d1 = 12.4, d2 = 12.41;
	TestClass tc1("leon", 29), tc2("marvin", 30);

	std::cout << "--------[swap test]--------" << std::endl;
	swap(int1, int2);
	std::cout << "int1 :" << int1 << std::endl;
	std::cout << "int2 :" << int2 << std::endl;
	std::cout << std::endl;
	std::cout << "---------[min test]---------" << std::endl;
	std::cout << "min int		:" << min(int3, int4) << std::endl;
	std::cout << "min double	:" << min(d1, d2) << std::endl;
	std::cout << "min TestClass	:" << min(tc1, tc2) << std::endl;
	std::cout << std::endl;
	std::cout << "---------[max test]---------" << std::endl;
	std::cout << "min int		:" << max(int3, int4) << std::endl;
	std::cout << "min double	:" << max(d1, d2) << std::endl;
	std::cout << "min TestClass	:" << max(tc1, tc2) << std::endl;
	std::cout << std::endl;
}