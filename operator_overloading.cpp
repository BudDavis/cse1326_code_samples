#include <iostream>
#include <cstring>

// demonstrate overloading the + operator to
// concatentate two strings

struct cstring
{
    char *x;
    cstring(char* a)
    {
        x = (char*) malloc(strlen(a)+1);
        strcpy(x,a);
    }
    cstring operator+ (char *n) 
    {
        char *t = (char*) malloc(strlen(x)+1);
        strcpy(t,x);
        x = (char*) malloc(strlen(t)+strlen(n)+1);
        strcat(x,t);
        strcat(x,n);
        free(t);
        return *this;
    }
};
int main(int argc,char* argv[])
{
    std::cout << "hello" << std::endl;
    cstring A((char*)"abc");
    A = A + (char*) "def";
    std::cout << A.x << std::endl;
    return 0;
}
