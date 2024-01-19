#include "Base.hpp"

int main() {
    Base obj;
    Base* objPtr = obj.generate();
    
    objPtr->identify(objPtr);
    delete objPtr;
    return 0;
}