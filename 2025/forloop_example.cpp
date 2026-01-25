#include <array>
#include <vector>
#include <stdio.h>


class  A
{
  public:
    int a;
    char b;
  public:
    A(int a_, char b_) 
    {
        a = a_;
        b = b_;
    }
};

//std::array<A,3> x = { A(5,'a'),A(1,'b'),A(1000,'z')};
std::vector<A> x;


void some_function(A& instanceA)
{
    instanceA.a=-1;
}

int main(int argc, char* argv[])
{
//auto elem: Copies each element by value. Suitable for small, cheap-to-copy types.
//const auto& elem: Accesses elements by constant reference. This is efficient and prevents accidental modification of elements within the loop.
//auto& elem: Accesses elements by mutable reference. Allows modification of the elements within the loop.

    x.push_back(A(5,'a'));
    x.push_back(A(1,'b'));
    x.push_back(A(1000,'z'));
    x[2] = A(22,'q');

    printf("the size is %ld\n",x.size());
    printf("begin %d %c \n",x.begin()->a,x.begin()->b);
    //printf("end %d %c \n",x.end()->a,x.end()->b);
    for ( A&  element:x) 
    {
        //element.b = 'm';
        //some_function(element);
        printf(" %d %c \n",element.a,element.b);
    }
    printf("after setting the char to m\n");
    for ( A&  element:x) 
    {
        //element.b = 'w';
        printf(" %d %c \n",element.a,element.b);
    }
}
