#include <iostream>
#include "Input.hpp"
#include "ScalarChar.hpp"
#include "ScalarInt.hpp"
#include "ScalarFloat.hpp"
#include "ScalarDouble.hpp"
#include "InvalidInputException.hpp"
#include <string>

int main(int ac, char* av[])
{
	Input* inputPtr;
	if (ac != 2)
	{
		std::cerr << "\e[31m" << "Write number." << "\e[0m" <<std::endl;
		return 1;
	}
	try
	{
		inputPtr = new Input(av[1]);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	ScalarChar sChar(*inputPtr);
	ScalarInt sInt(*inputPtr);
	ScalarFloat sFloat(*inputPtr);
	ScalarDouble sDouble(*inputPtr);

	sChar.prtValueInfo();
	sInt.prtValueInfo();
	sFloat.prtValueInfo();
	sDouble.prtValueInfo();
	delete inputPtr;
	return 0;
}