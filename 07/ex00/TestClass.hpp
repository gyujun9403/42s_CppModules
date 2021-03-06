#ifndef TEST_CLASS_HPP
#define TEST_CLASS_HPP
#include <string>
#include <iostream>

class TestClass
{
	// ****************[canonical class form]****************
public:
	TestClass(); // default constructor
	virtual ~TestClass(); // destructor
	TestClass(const TestClass& other); // copy constructor
	TestClass& operator=(const TestClass& other); // (copy) assignment operator
	// ******************************************************
private:
	std::string name_;
	int old_;

public:
	TestClass(std::string name, int old);
	bool operator==(TestClass& theOther);
	bool operator>(TestClass& theOther);
	bool operator<(TestClass& theOther);
	bool operator>=(TestClass& theOther);
	bool operator<=(TestClass& theOther);
	std::string getName() const;
	int getOld() const;
};
std::ostream& operator<<(std::ostream& os, const TestClass& tc);

#endif
