#include <cstdint>
#include <limits>
#include <iostream>
// example from textbook, p198 or thereabouts
int main() {
    // silent truncation
    {
       double x = 2.7182818284590452353602874713527L;
       uint8_t  y = x; // Silent truncation
       std::cout << x << "--> " << int(y) << std::endl;
    }
    {
    // Brace Initialization
        double x = 2.7182818284590452353602874713527L;
        uint8_t  y = {x}; 
        // narrowing causes a warning
        std::cout << x << "--> " << int(y) << std::endl;
     }
     {
         // does not fit (narrowing)
         // implementation defined
         uint8_t x = 0b111111111; // 255
         int8_t y = 0b111111111; // Implementation defined.
         printf("x: %u\ny: %d", x, y);
     }
     {
         // float mismatch sizesthat does not fit
         // 
         double x = std::numeric_limits<float>::max();
         long double y = std::numeric_limits<double>::max();
         float z = std::numeric_limits<long double>::max();  // Undefined Behavior
         float z2 = { std::numeric_limits<long double>::max() };  // Undefined Behavior
         printf("line 32 x: %g\ny: %Lg\nz: %g\n", x, y, z);
         printf("line 33 z2 = %f z = %f\n",z2, z);
     }
     {
         // ptr to bool
         bool b;
         int a;
         int *ptr = &a;
         b = ptr;
         std::cout << "the bool is " << b << std::endl;
     }
     {
         // any pointer to void
         int i;
         int *ptr = &i;
         void *x;

         x=ptr;
         printf("the ptr is %p\n",x);
     }
     return 0;
}
