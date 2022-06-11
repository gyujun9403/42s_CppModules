#include <iostream>
#include "MutantStack.hpp"

template<typename T>
void prtMutantStackAll(MutantStack<T>& mstack)
{
    size_t i = 0;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << "iter[" << i++ << "] :" << *it << std::endl;
        ++it;
    }
}

int main()
{
    std::cout << "[TEST 0] :push, pop, etc... and print all elements" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(42);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    prtMutantStackAll(mstack);
    std::cout << "-------------------------------------------\n" << std::endl;
    std::cout << "[TEST 1] :copy MutantStack to std::stack" << std::endl;
    std::stack<int> s(mstack);
    mstack.push(111);
    std::cout << "s top :" << s.top() << std::endl;
    std::cout << "-------------------------------------------\n" << std::endl;

    std::cout << "[TEST 2] :copy constructor test" << std::endl;
    MutantStack<int> mstackCpy(mstack);
    mstack.push(4242);
    mstack.push(424242);
    std::cout << "{org}" << std::endl;
    prtMutantStackAll(mstack);
    std::cout << "{copy}" << std::endl;
    prtMutantStackAll(mstackCpy);
    std::cout << "-------------------------------------------\n" << std::endl;

    std::cout << "[TEST 3] :assignment operatorcopy test" << std::endl;
    mstack = mstackCpy;
    prtMutantStackAll(mstack);
    return 0;
}