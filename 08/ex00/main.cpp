#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <stack>

int main()
{
    std::vector<int> vecVer;
    std::list<int> listVer;
    std::set<int> setVer;
    std::deque<int> dequeVer;
    std::stack<int> stackVer;

    for (int i = 0; i < 42; i++)
    {
        vecVer.push_back(i);
        listVer.push_back(i);
        setVer.insert(i);
        dequeVer.push_back(i);
        stackVer.push(i);
    }
    try
    {
        std::vector<int>::iterator iterVec = easyfind(vecVer, 7);
        std::cout << "vector " << *iterVec << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "vector " << e.what() << '\n';
    }
    try
    {
        std::list<int>::iterator iterList = easyfind(listVer, 7);
        std::cout << "list " << *iterList << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "list " << e.what() << '\n';
    }
    try
    {
        std::set<int>::iterator iterSet = easyfind(setVer, 7);
        std::cout << "set " << *iterSet << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "set " << e.what() << '\n';
    }
    try
    {
        std::deque<int>::iterator iterDeque = easyfind(dequeVer, 7);
        std::cout << "deque " << *iterDeque << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "deque " << e.what() << '\n';
    }
    /* 🔥compile error occur
    main.cpp:63:5: error: no matching function for call to 'easyfind'
    easyfind(stackVer, 7);
    ^~~~~~~~
    ./easyfind.hpp:10:22: note: candidate template ignored: substitution failure [with C = std::__1::stack<int,
        std::__1::deque<int, std::__1::allocator<int> > >]: no type named 'iterator' in 'std::__1::stack<int,
        std::__1::deque<int, std::__1::allocator<int> > >'
    typename C::iterator easyfind(C& constainer, int element) throw(std::exception)
                ~~~~~~~~ ^
    1 error generated.
    */
    //easyfind(stackVer, 7);
}