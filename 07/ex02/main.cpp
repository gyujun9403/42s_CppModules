#include <iostream>
#include "Array.hpp"

int main()
{
	// argument list for class template "Array" is missingC/C++(441)
	//Array arr(4);
	Array<int> arr(4);

	arr[0] = 21;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 7;
	try
	{
		arr[4] = 7;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << arr[1] << std::endl;
}