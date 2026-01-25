#include <iostream>

struct SomeClass
{
    int a;
    bool b;
    SomeClass()
    {
        std::cout << "in constructor" << std::endl;
        a=0;
        b=false;
    }
};

int main(int argc, char* argv[])
{
    SomeClass* A;
    SomeClass* B;
    A = new SomeClass;
    std::cout << B->b << std::endl;
    return 0;
}
