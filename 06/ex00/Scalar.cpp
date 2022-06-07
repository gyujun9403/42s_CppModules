#include "Scalar.hpp"

Scalar::Scalar() {}

Scalar::Scalar(const Scalar& other)
:isNan_(other.isNan_), isInf_(other.isInf_) {}

Scalar::Scalar(const Input& input)
: orgScalar_(input.getValue()), isNan_(input.isNan()), isInf_(input.isInf()) {}

Scalar& Scalar::operator=(const Scalar& other)
{
	this->orgScalar_ = other.orgScalar_;
	this->isInf_ = other.isInf_;
	this->isNan_ = other.isNan_;
	return (*this);
}

void Scalar::setScalar(const Input& input)
{
	this->orgScalar_ = input.getValue();
	this->isInf_ = input.isInf();
	this->isNan_ = input.isNan();
}

double Scalar::getOrgValue() const
{
	return this->orgScalar_;
}

Scalar::~Scalar() {}
