#include "Scalar.hpp"

Scalar::Scalar() {}

Scalar::Scalar(const Scalar& other)
{
	static_cast<void>(other);
}

Scalar& Scalar::operator=(const Scalar& other)
{
	static_cast<void>(other);
	return (*this);
}

Scalar::~Scalar()
{
	;
}
