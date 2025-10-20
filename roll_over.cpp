#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int start;
    unsigned int end;

    start = 0x200;
    end   = 0x100;
    printf("normal %x\n", (start - end) & 0xFFFFFF);
    start = 0x100;
    end   = 0x200;
    printf("over %x\n", (start - end) & 0xFFFFFF);
    return 0;
}

//return (start - end) & 0xFFFFFF;     // handle wrap around
