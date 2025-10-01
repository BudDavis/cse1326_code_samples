#include <cstdio>

// a generic implementation of min
template <typename T>
T min(T A, T B)
{
  if (A<B)
    return A;
  else
    return B;
}

int main(int argc, char*argv[])
{
    int a,b;
    a=10; b=2;

    printf("%d\n",min<int>(a,b));
    printf("%d\n",min<int>(min(a,b),0));
    return 0;
}
