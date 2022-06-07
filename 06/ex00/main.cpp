#include <iostream>
#include "Input.hpp"
#include "ScalarChar.hpp"
#include "ScalarInt.hpp"
#include "ScalarFloat.hpp"
#include "ScalarDouble.hpp"
#include "InvalidInputException.hpp"
#include <string>

// 데이터 클래스를 받고 이를 변화하여 출력해줄 클래스 각 자료형 별로.
// 데이터 변환한 데이터 정보를 담을 클래스

int main(int ac, char* av[])
{
	Input* inputPtr;
	if (ac != 2)
		return 1;
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