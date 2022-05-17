#ifndef EASY_FINDER_HPP
#define EASY_FINDER_HPP

// easyfind find element in container
// if find, return it. if not find, throw exception.
template<typename T>
T easyfind(T& constainer, int element)
{
	try
	{
		/* code */
		T::find()
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

#endif
