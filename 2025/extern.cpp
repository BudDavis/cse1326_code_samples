#include <stdio.h>
int afunc();

int main()
{
    afunc();
    printf("hello\n");
    afunc();
    afunc();
    return 0;
}
int afunc ()
{
    //static int j=0;
    int j=0;
    j++;
    printf("hello %d\n",j);
    return 0;
}
