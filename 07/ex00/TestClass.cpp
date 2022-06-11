#include "TestClass.hpp"

TestClass::TestClass(): name_("default"), old_(0) {}

TestClass::~TestClass() {}

TestClass::TestClass(const TestClass& other)
{
	this->name_ = other.name_;
	this->old_ = other.old_;
}

TestClass& TestClass::operator=(const TestClass& other)
{
	this->name_ = other.name_;
	this->old_ = other.old_;
	return (*this);
}

TestClass::TestClass(std::string name, int old)
{
	this->name_ = name;
	this->old_ = old;
}

bool TestClass::operator==(TestClass& theOther)
{
	if (this->old_ == theOther.old_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestClass::operator>(TestClass& theOther)
{
	if (this->old_ > theOther.old_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestClass::operator<(TestClass& theOther)
{
	if (this->old_ < theOther.old_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestClass::operator>=(TestClass& theOther)
{
	if (this->old_ >= theOther.old_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestClass::operator<=(TestClass& theOther)
{
	if (this->old_ <= theOther.old_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string TestClass::getName() const
{
	return this->name_;
}
int TestClass::getOld() const
{
	return this->old_;
}

std::ostream& operator<<(std::ostream& os, const TestClass& tc)
{
	return os << tc.getName() << ", " << tc.getOld();
}
