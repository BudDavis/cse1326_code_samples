#include <cstdio>
struct Beverage
{
  char *name; // The name of the beverage
  float size; // serving amount, in ounces
  bool hot;   // true of the beverage is served > 100 degrees F
  Beverage(char *n,float s,bool h)
  {
      name = strdup(n);
      size = s;
      hot = h;
      if (size < 6.0)
          size = 6.0;
      if (size>32.0)
          size = 32.0;
  }
};

void
make_beverage_cold (Beverage& someBev)
{
  someBev.hot = false;
}

int
main (int argc, char *argv[])
{
  Beverage B = { (char *)"coffee", 12.0, 1 };
  printf ("%d\n", B.hot);
  make_beverage_cold (B);
  printf ("%d\n", B.hot);
  return 0;
}
