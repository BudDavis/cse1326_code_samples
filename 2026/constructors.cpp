#include <cstdio>
#include <cstring>
#include <cstdlib>
// g++ -std=gnu++17 -Wall constructors.cpp 
enum class Food {WET,DRY,BOTH};
enum class Nose {PINK,BLACK};
enum class Job {COMPANION, SECURITY, RODENT_HUNTER};
struct Cat
{
    char *name;
    Food eats;
    Nose snout;
    Job  works_as_a;
    Cat(char *name_,Food eats_,Nose snout_,Job works_as_a_):name(name_),eats(eats_),snout(snout_),works_as_a(works_as_a_) 
    {
    }
#if 0
    Cat(char* na,Food F,Nose N,Job J)
    {
        name = (char*) malloc(strlen(na));
        strcpy(name,na);
        eats = F;
        snout = N;
        works_as_a = J;
    }
#endif
    ~Cat()
    {
        if (name) 
        { 
            free(name);
            name=nullptr;
        }
    }
};

int main(int argc,char *argv[])
{
    Cat A = Cat((char*)"microwave",Food::BOTH,Nose::PINK,Job::COMPANION);
    Cat *B = new Cat((char*)"twist",Food::DRY,Nose::PINK,Job::COMPANION);
    return 0;
}
