#include <limits>
#include <cstdio>
#include <cstdint>
#include <cstdlib>

// from textboox, p201
void trainwreck(const char* read_only) 
{
    // auto ??
     unsigned char* as_unsigned = (unsigned char*)read_only;
     *as_unsigned = 'b';  // Crashes on Windows 10 x64
}

int main() 
{
   int64_t b = std::numeric_limits<int64_t>::max();
   int32_t c(b);  // The compiler abides.
   // note no warning
   if (c != b) 
       printf("Narrowing conversion!\n"); 
   printf(" %lu %x \n",b,c);
   {
       auto ezra = "Ezra";
       printf("Before trainwreck: %s\n", ezra);
       trainwreck(ezra);
       printf("After trainwreck: %s\n", ezra);
    }
}
