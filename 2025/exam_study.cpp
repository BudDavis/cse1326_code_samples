#include <cstdio>
#include <cstring>
#include <cstdlib>

struct CoffeeBeverage
{ 
   char *name;
   int size;
   CoffeeBeverage *next;
   CoffeeBeverage(char* n,int s): name(n),size(s),next(nullptr) {};
   CoffeeBeverage(CoffeeBeverage& original)
   {
       name=(char*)malloc(strlen(original.name)+1);
       strcpy(name,original.name);
       if (original.next) 
       {
           next = new CoffeeBeverage(*(original.next));
       }
   }
};

int main(int argc, char *argv[])
{
    CoffeeBeverage *A = new CoffeeBeverage( (char*)"black coffee",12.0);
    CoffeeBeverage *B = new CoffeeBeverage( (char*)"latte",10.0);
    CoffeeBeverage *C = new CoffeeBeverage( (char*)"americano",4.0);
    A->next=B;
    B->next=C;
    C->next=nullptr;
    CoffeeBeverage *D = nullptr;
    D = new CoffeeBeverage(*A);
    printf("%p %s\n",A->name,A->name);
    printf("%p %s\n",D->name,D->name);
    delete A;
    delete B;
    delete C;
    delete D;
    return 0;
}


//"black coffee", 12

//"latte",10

//"americano",4

//link them together (set up the next pointer) such that 'black coffee' leads to 'latte' which leads to 'americano' which leads to 'nullptr'.

//Write code that deletes all of the objects.

//Write a copy constructor that performs a 'deep copy'.
