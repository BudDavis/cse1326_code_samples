#include <iostream>
void b(int i)
{
    std::cout << "i am in b " << i <<  std::endl;
}
int a()
{
    int i=0;
    b(i);
    return 2;
}
int main(int argc, char* argv[])
{
    int x[25]={0};

    double sum=0;
    for (unsigned int i=0;i<25;i++)
    {
        sum=sum+x[i];
        a();
    }
    return 0;
}
