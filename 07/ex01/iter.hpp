#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// iter function do 'func' about every elements of array
template<typename T>
void iter(T* ptrArray, size_t lenArray, void (*func)(T &));

#endif