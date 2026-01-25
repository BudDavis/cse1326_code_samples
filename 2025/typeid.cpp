#include <cstdio>
#include <iostream>
#include <typeinfo>

// demonstrates typeid, for debugging purposes
//

struct someClass
{
    int i;
    float f;
};

int main(int argc,char *argv[])
{
    float f;
    someClass S;
    printf("%s\n",typeid(12+12).name());
    std::cout << typeid(12.0).name() << std::endl;
    std::cout << typeid(12.0).name() << std::endl;
    std::cout << typeid(f).name() << std::endl;
    std::cout << typeid(S).name() << std::endl;
    std::cout << typeid(S.f).name() << std::endl;
    return 0;
}
