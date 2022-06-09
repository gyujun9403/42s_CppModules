#ifndef EASY_FINDER_HPP
#define EASY_FINDER_HPP

#include <algorithm>
#include <exception>

// easyfind find element in container
// if find, return it. if not find, throw exception.
template<typename C>
typename C::iterator easyfind(C& constainer, int element) throw(std::exception)
{
	typename C::iterator iterEnd, iterRt;
	iterEnd = constainer.end();
	iterRt = std::find(constainer.begin(), iterEnd, element);
	if (iterRt == iterEnd)
	{
		throw (std::runtime_error("constainer doesn't have element."));
	}
	else 
	{
		return iterRt;
	}
}

#endif
