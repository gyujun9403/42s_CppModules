#ifndef WHAT_EVER_HPP
#define WHAT_EVER_HPP

template<typename T>
void swap(T& one, T& theOther)
{
	T temp;
	temp = one;
	one = theOther;
	theOther = temp;
}

template<typename T>
T min(T& one, T& theOther)
{
	if (one >= theOther)
	{
		return theOther;
	}
	else
	{
		return one;
	}
}

template<typename T>
T max(T& one, T& theOther)
{
	if (one <= theOther)
	{
		return theOther;
	}
	else
	{
		return one;
	}
}

#endif
