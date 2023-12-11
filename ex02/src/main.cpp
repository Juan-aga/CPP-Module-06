#include "Base.hpp"

#include <iostream>
#include <ctime>

#define TEST 10

Base *  generate( void );
void    indentify( Base * p );
void    indentify( Base & p );

int main( void )
{
    Base * test;

    std::srand(std::time(NULL));
    for (int i=0; i < TEST; i++)
    {
        std::cout << "Test " << i + 1 << std::endl;
        test = generate();
        indentify(test);
        indentify(*test);
        delete test;
        std::cout << std::endl;
    }
    return 0;
}

Base *  generate( void )
{
    int result;
    
    if (DEBUG)
    {
        result = std::rand() % 4;
        std::cout << "Random number: " << result << " generating: ";
        if (result > 2)
            std::cout << "Base\n";
        else
            std::cout << static_cast<char>('A' + result) << std::endl;
    }
    else
        result = std::rand() % 3;
    if (!result)
        return new A;
    else if (result == 1)
        return new B;
    else if (result == 2)
        return new C;
    else
        return new Base;
}

void    indentify( Base * p )
{
    std::cout << "Actual type ptr is: ";
    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "C\n";
    else
        std::cout << "Base\n";
}

void    indentify( Base & p )
{
    std::cout << "Actual type reference is: ";
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
        return ;
    }
    catch (std::exception & e)
    {}
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
        return ;
    }
    catch (std::exception & e)
    {}
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
        return ;
    }
    catch (std::exception & e)
    {}
    std::cout << "Base\n";
}
