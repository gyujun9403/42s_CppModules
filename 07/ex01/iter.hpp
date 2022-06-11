#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// iter function do 'func' about every elements of array
template<typename T>
void iter(T* ptrArray, size_t lenArray, void (*func)(T&))
{
	if (!(ptrArray == NULL || lenArray == 0 || func == NULL))
	{
		for (size_t i = 0; i < lenArray; i++)
		{
			func(ptrArray[i]);
		}
	}
}

#endif
