#include <iostream>
#include "Array.hpp"

int main()
{
	// argument list for class template "Array" is missingC/C++(441)
	//Array arr(4);
	Array<int> arr1(4), arr2;
	Array<std::string> str1(3), str2;

	{
		std::cout << "--------[arr1]--------" << std::endl;
		std::cout << "> show allocating arr1 using operator[] and throwing std::exception" << std::endl;
		arr1[0] = 1;
		arr1[1] = 3;
		arr1[2] = 5;
		try
		{
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "arr1[" << i << "] :" << arr1[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "----------------------\n" << std::endl;
	}
	{
		std::cout << "--------[arr2]--------" << std::endl;
		std::cout << "> show creating an empty array" << std::endl;
		std::cout << "&arr2 :"  << &arr2 << std::endl;
		try
		{
			std::cout << "arr2[0] :" << arr2[0] << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "----------------------\n" << std::endl;
	}
	{
		std::cout << "--------[str1]--------" << std::endl;
		std::cout << "> show Array Class can use std::string class's func and operator" << std::endl;
		str1[0].assign("gy");
		str1[0].append("eo");
		str1[0] = str1[0] + "n";
		str1[2] = "hello World";
		try
		{
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str1[" << i << "] :" << str1[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "------[str2 copy]------" << std::endl;
		std::cout << "> show Array Class can copy std::string's copy " << std::endl;
		std::cout << "[before copy]" << std::endl;
		try
		{
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str2[" << i << "] :" << str2[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		str2 = str1;
		std::cout << "[after copy]" << std::endl;
		try
		{
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str2[" << i << "] :" << str2[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "----------------------\n" << std::endl;
	}
}