
#include "iter.hpp"

template<typename T>
void iter(T* ptrArray, size_t lenArray, void (*func)(T &))
{
	if (ptrArray == NULL || lenArray == 0 || func == NULL)
	{
		return ;
	}
	for (size_t i = 0; i < lenArray; i++)
	{
		func(ptrArray[i]);
	}
}