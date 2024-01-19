#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
Base::~Base() 
{
    std::cout << "Destructor Called" << std::endl;
}

Base* Base::generate() 
{
    std::srand(std::time(0));
    int random = std::rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else if(random == 2)
        return new C();
    else
    {
        std::cout << "ERROR: Doesn't casting" << std::endl;
        return nullptr;
    }
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl; 
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr) 
        std::cout << "C" << std::endl;
}

void Base::identify(Base& p) {identify(&p);}