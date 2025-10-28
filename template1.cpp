#include <cstdio>
#include <string>

// a generic implementation of min
template <typename T1,typename T2>
T1 min(T1 A, T2 B)
{
  if (A<B)
    return A;
  else
    return T1(B);
}

template <typename  C>
struct someClass
{
    C item;
};

int main(int argc, char*argv[])
{
    int a,b;
    a=10; b=2;
   
    someClass<int> SC;

    //printf("%s\n",min<std::string>("aaa","bbb").c_str());

    //printf("%f\n",min<float,int>(100.0,10));
    printf("%f\n",min(100.0,10));

    //printf("%d\n",min<int>(min(a,b),0));
    return 0;
}
