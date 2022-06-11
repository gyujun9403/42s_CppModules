#include <string>
#include <limits>
#include <algorithm>
#include "Span.hpp"

#include <iostream>

Span::Span() {}

Span::~Span(){}

// deep copy되는지 확인. https://m.cplusplus.com/reference/vector/vector/vector/
Span::Span(const Span& other)
: N_(other.N_), vecData_(other.vecData_) {}

Span& Span::operator=(const Span& other)
{
    this->N_ = other.N_;
    // https://m.cplusplus.com/reference/vector/vector/operator=/
    this->vecData_ = other.vecData_;
    return *this;
}

Span::Span(unsigned int N): N_(N){}

void Span::addNumber(int element) throw(std::exception)
{
    if (this->vecData_.size() + 1 > N_)
    {
        std::string except = "You cannot store more than " +
                                std::to_string(N_) + " elements.";
        throw (std::runtime_error(except));
    }
    else
    {
        this->vecData_.push_back(element);
        if (this->isSorted_ == true)
        {
            this->isSorted_ = false;
        }
    }
}



unsigned int Span::shortestSpan() throw(std::exception)
{
    iterVec iterBegin;
    iterVec iterEnd;
    unsigned int minSpan = UINT32_MAX;

    if (vecData_.size() < 2)
    {
        throw (std::runtime_error("Not enough elements stored to get span."));
    }
    if (this->isSorted_ == false)
    {
        std::sort(vecData_.begin(), vecData_.end());
        isSorted_ = true;
    }
    iterBegin = vecData_.begin();
    iterEnd = vecData_.end();
    for (iterVec iter = iterBegin; (iter + 1) != iterEnd; iter++)
    {
        if (static_cast<unsigned int>(*(iter + 1) - *iter) < minSpan)
        {
            minSpan = *(iter + 1) - *iter;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() throw(std::exception)
{
    if (vecData_.size() < 2)
    {
        throw (std::runtime_error("Not enough elements stored to get span."));
    }
    if (this->isSorted_ == false)
    {
        std::sort(vecData_.begin(), vecData_.end());
        isSorted_ = true;
    }
    return *(vecData_.end() - 1) - *vecData_.begin();
}
