
//Examples of a static member of a class, and its storage

//Use them for keeping track of how many instances exist??

#include <iostream>

struct cat 
{
   static bool backClaws;
   bool frontClaws;
   float weight;
   float numColors; 
   static int catCount;
   cat()
   {
	   catCount++;
   }
   ~cat()
   {
	   catCount--;
   }
};

bool cat::backClaws = true;
int cat::catCount = 0;

int main() 
{
    std::cout << cat::backClaws << std::endl;
    cat::backClaws = false;
    std::cout << cat::backClaws << std::endl;
    cat a;
    cat b;
    std::cout << "cat a" << std::endl;
    std::cout << a.backClaws << &a.backClaws << std::endl; 
    std::cout << a.frontClaws << &a.frontClaws << std::endl; 

    std::cout << "cat b" << std::endl;
    std::cout << b.backClaws << &b.backClaws << std::endl; 
    std::cout << b.frontClaws << &b.frontClaws << std::endl; 

    std::cout << "number of objects " << cat::catCount << std::endl;
}
