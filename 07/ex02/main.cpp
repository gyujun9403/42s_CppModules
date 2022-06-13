#include <iostream>
#include "Array.hpp"
#define MAX_VAL 750

int main()
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	// argument list for class template "Array" is missingC/C++(441)
	//Array arr(4);
	Array<int> arr1(4), arr2;
	Array<std::string> str1(3), str2;
	{
		std::cout << "--------[arr1]--------" << std::endl;
		std::cout << "> show allocating arr1 using operator[] and throwing std::exception" << std::endl;
		try
		{
			arr1[0] = 1;
			arr1[1] = 3;
			arr1[2] = 5;
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "arr1[" << i << "] :" << arr1[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
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
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		}
		std::cout << "----------------------\n" << std::endl;
	}
	{
		std::cout << "--------[str1]--------" << std::endl;
		std::cout << "> show Array Class can use std::string class's func and operator" << std::endl;
		try
		{
			str1[0].assign("gy");
			str1[0].append("eo");
			str1[0] = str1[0] + "n";
			str1[2] = "hello World";
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str1[" << i << "] :" << str1[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		}
		std::cout << "------[str2 assignment]------" << std::endl;
		std::cout << "> show Array Class can assign" << std::endl;
		std::cout << "[before assignment]" << std::endl;
		try
		{
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str2[" << i << "] :" << str2[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		}
		str2 = str1;
		std::cout << "[after assignment]" << std::endl;
		try
		{
			str2[0].append("2");
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str2[" << i << "] :" << str2[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		}
		std::cout << "------[str3 copy constructor]------" << std::endl;
		Array<std::string> str3(str1);
		try
		{
			str3[0].append("3");
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str3[" << i << "] :" << str3[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		}
		std::cout << "------[str1, original]------" << std::endl;
		try
		{
			for (int i = 0; i < 5000000; i++)
			{
				std::cout << "str1[" << i << "] :" << str1[i] << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
		}
		std::cout << "----------------------\n" << std::endl;
	}
}