// from book
#include <cstdio>
#include <stdexcept>
struct Groucho
{
  void
  forget (int x)
  {
    try
      {
        if (x == 0xFACE)
          {
            throw std::runtime_error{ "I'd be glad to make an exception." };
          }
      }
    catch (const std::runtime_error &e)
      {
        printf ("ok, caught it. now lets keep going.\n");
      }
    printf ("Forgot 0x%x\n", x);
  }
};

int
main ()
{
  Groucho groucho;
  // try
  //   {
  groucho.forget (0xC0DE);
  groucho.forget (0xFACE);
  groucho.forget (0xC0FFEE);
  //  }
  // catch (const std::runtime_error &e)
  //   {
  //     printf ("exception caught with message: %s\n", e.what ());
  //   }
}
