#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data
{
	std::string name;
	int value1;
	double value2;
};

class Serializer
{
	// ****************[canonical class form]****************
public:
	Serializer();								// default constructor
	virtual ~Serializer();					// destructor
	Serializer(const Serializer& other);			// copy constructor
	Serializer& operator=(const Serializer& other);	// (copy) assignment operator
	// ******************************************************
public:
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif