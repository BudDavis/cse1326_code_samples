#include <cstdio>
int main() 
{
   int i = 55;
   int k = 2;
   {
       int i=1;
       int k=2;
       auto increment = [j=i,&k](auto x, int y) mutable { return j + x + y; };

      printf("increment(10) = %d\n", increment(10,1)); 
      printf("increment(10, 5) = %d\n", increment(10, 5)); 
   }
   return 0;
}
