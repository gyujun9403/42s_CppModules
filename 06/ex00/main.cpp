#include <iostream>
#include "Input.hpp"
#include "ScalarChar.hpp"
#include "InvalidInputException.hpp"
#include <string>

// 데이터 클래스를 받고 이를 변화하여 출력해줄 클래스 각 자료형 별로.
// 데이터 변환한 데이터 정보를 담을 클래스

int main(int ac, char* av[])
{
	if (ac != 2)
		return 1;
	try
	{
		Input input(av[1]);
		input.compileInput();
		ScalarChar sChar(input);
		sChar.prtValueInfo();
	}
	// libc++abi.dylib: terminating with unexpected exception of type InvalidInputException
	// std::exception관련 문제.
	catch(const InvalidInputException& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}