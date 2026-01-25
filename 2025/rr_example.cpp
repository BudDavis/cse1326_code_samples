/*
 * rr record ./your_program --arg1 arg2
 * rr replay
 *
 *
reverse-continue or rc: Go to the previous breakpoint.
reverse-next or rn: Step backward by one instruction.
reverse-step or rs: Step backward into a function call.
reverse-finish or rf: Execute backward until the beginning of the current function.
 */

#include <stdio.h>

int X;

void a()
{
    X = 1;
}

void b()
{
    X = 2;

}

void c()
{
    X = 3;
}

int main(int argc,char* argv[])
{
    a();
    b();
    c();
    printf("%d\n",X);
    return 0;
}
