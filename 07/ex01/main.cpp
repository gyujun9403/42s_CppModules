#include "iter.hpp"
#include <iostream>
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

int main()
{
	char a[3] = {'A', 'B', 'C'};

	std::cout << "--[original]--\n" <<
	"a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] << "\n" << std::endl;
	
	iter(a, 3, ft_tolower);
	std::cout << "---[Lower]---\n" <<
	"a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] << "\n" << std::endl;

	iter(a, 3, ft_toupper);
	std::cout << "---[Upper]---\n" <<
	"a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] << "\n" << std::endl;
}