#include <cstdlib>
#include <stdio.h>

class someClass
{
public:
  char name;
  char *fullName;
  someClass (char n)
  {
    printf ("calling constructor\n");
    fullName = (char *)malloc (2);
    name = n;
    fullName[0] = n;
    fullName[1] = '\0';
  }
  someClass (const someClass &y); // copy constructor
  ~someClass ();                  // destructor
};

someClass make_one()
{
    someClass S=someClass('d');
    return S;
}

#if 1
someClass::someClass (const someClass &y)
{
  printf ("calling copy constructor\n");
  printf ("y.n = %c\n", y.name);
  name = y.name;
  fullName = (char *)malloc (2);
  fullName[0] = y.name;
  fullName[1] = '\0';
  // printf("%s\n",fullName);
}
#endif

someClass::~someClass ()
{
  // free up memory....
  if (0 && fullName)
    {
      free (fullName);
      fullName = nullptr;
    }
  printf ("calling destructor\n");
}

void IncrementName(someClass& x)
{
    x.name='Z';
    if(x.name=='z')
    {
        printf("\n");
    }
}

int
main (int argc, char *argv[])
{
  // just the class
  //
#if 0
  someClass x ('x');
  printf ("%c %p %s \n", x.name, x.fullName, x.fullName);
  // a copy
  someClass z = someClass (x);
  printf ("after the copy constructor\n");
  printf (" x is %c %p %s \n", x.name, x.fullName, x.fullName);
  printf (" z is %c %p %s \n", z.name, z.fullName, z.fullName);
    someClass a('a');
    someClass b('b');
    printf("assignment\n");
    b = a;
    printf("b is %c %p %s\n",b.name,b.fullName,b.fullName);
    printf("a is %c %p %s\n",a.name,a.fullName,a.fullName);
#endif
#define CALLING_A_FUNCTION
#ifdef CALLING_A_FUNCTION
    printf("creating object\n");
    someClass b('b');
    printf("calling increment \n");
    IncrementName(b);
    printf("b is %c %p %s\n",b.name,b.fullName,b.fullName);
#endif
#if 0
    someClass a('a');
    a = make_one();
#endif
  return 0;
}
