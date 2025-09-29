#include <cstdio>

struct aClass
{
    int aInt;
    double aDouble;
    aClass()
    {
        printf("in the constructor %p\n",this);
    }
    ~aClass()
    {
        printf("destructing aClass instance %p\n",this);
    }
};

int main (int argc, char *argv[])
{
    aClass *ptr = nullptr;
    aClass instance;
    if (argc==2)
    {
        ptr = new aClass();
        printf("ptr is %p\n",ptr);
        printf("the arguments are %s %s\n",argv[1],argv[2]);
        aClass z;
    }
    if (ptr)
    {
        delete ptr;
    }
    return 0;
}
