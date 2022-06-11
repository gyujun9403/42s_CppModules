#include "iter.hpp"
#include <iostream>
#include <cctype>

void ftTolower(char &arr)
{
	arr = std::tolower(arr);
}

void ftToupper(char &arr)
{
	arr = std::toupper(arr);
}

int main()
{
	char a[3] = {'A', 'B', 'C'};

	std::cout << "--[original]--\n" <<
	"a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] << "\n" << std::endl;
	
	// 🌟
	iter(a, sizeof(a) / sizeof(a[0]), ftTolower);
	std::cout << "---[Lower]---\n" <<
	"a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] << "\n" << std::endl;

	// 🌟
	iter(a, sizeof(a) / sizeof(a[0]), ftToupper);
	std::cout << "---[Upper]---\n" <<
	"a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] << "\n" << std::endl;
}
