#include "Span.hpp"
#include <iostream>
#include <limits>

int main()
{
    {
        std::cout << "[TEST0] : subject" << std::endl;
        Span sp = Span(5);
        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "---------------------------\n" << std::endl;
    }
    {
        std::cout << "[TEST1] : more than N" << std::endl;
        Span span(10);
        try
        {
            span.addNumber(400000);
            span.addNumber(400010);
            span.addNumber(1);
            span.addNumber(2);
            span.addNumber(-4);
            span.addNumber(-3);
            span.addNumber(0);
            span.addNumber(0);
            span.addNumber(386573);
            span.addNumber(-7); //10th element.
            span.addNumber(-424242);
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "longestSpan :" << span.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "shortestSpan :" << span.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        std::cout << "---------------------------\n" << std::endl;
    }
    {
        std::cout << "[TEST2] : int MAX / MIN" << std::endl;
        Span span(2);
        try
        {
            span.addNumber(INT32_MAX);
            span.addNumber(INT32_MIN);
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "longestSpan :" << span.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "shortestSpan :" << span.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        std::cout << "---------------------------\n" << std::endl;
    }
    {
        std::cout << "[TEST3] : just 1 element" << std::endl;
        Span span(1);
        try
        {
            span.addNumber(INT32_MAX);
            span.addNumber(INT32_MIN);
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "longestSpan :" << span.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "shortestSpan :" << span.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        std::cout << "---------------------------\n" << std::endl;
    }
    {
        std::cout << "[TEST4] :  : 0 element" << std::endl;
        Span span(0);
        try
        {
            span.addNumber(INT32_MAX);
            span.addNumber(INT32_MIN);
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "longestSpan :" << span.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "shortestSpan :" << span.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        std::cout << "---------------------------\n" << std::endl;
    }
    {
        std::cout << "[TEST4] : 10000 elements" << std::endl;
        Span span(10000);
        try
        {
            for (int i = -5000; i < 4997; i++)
            {
                span.addNumber(i);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "longestSpan :" << span.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "shortestSpan :" << span.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }

        try
        {
            span.addNumber(INT32_MAX);
            span.addNumber(INT32_MIN);
            span.addNumber(0); // 10000th element
            span.addNumber(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "longestSpan :" << span.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
        try
        {
            std::cout << "shortestSpan :" << span.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "\e[31m" << e.what() << "\e[0m" << '\n';
        }
    }
}