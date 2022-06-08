#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "TypeFinder.hpp"
#include <unistd.h>

int main()
{
	Base* ptr;
	for (int i = 0; i < 6; i++)
	{
		ptr = TypeFinder::generate();
		TypeFinder::identify(ptr);
		TypeFinder::identify(*ptr);
		delete ptr;
		sleep(1);
	}
	ptr = new Base();
	TypeFinder::identify(ptr);
	TypeFinder::identify(*ptr);
	delete ptr;
}
