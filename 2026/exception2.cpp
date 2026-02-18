#include <stdio.h>
#include <exception>
#include <fenv.h>

double divide_by(double a,double b)
{
    double res;
    try {
        res =  a/b;
    }
    catch (std::exception& e)
    {
        printf("caught the exception at %s %d \n",__FILE__,__LINE__);
        throw;
    }
    return res;
}

int main(int argc,char *argv[])
{
    feenableexcept(FE_INVALID);
    printf(" %f\n",divide_by(10.0,0.0));
    printf(" %f\n",divide_by(0.0,0.0));
    return 0;
}
