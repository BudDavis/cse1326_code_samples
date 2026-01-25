//  g++ references_example.cpp -std=gnu++17 -g -Wall
#include <stdio.h>
// change to int& a and see the difference
void set_to_zero (int& a)
{
    a = 0;
}

int main(int argc,char* argv[])
{
    int i=100;
    set_to_zero(i);
    printf("i is %d\n",i);
    return 0;
}
