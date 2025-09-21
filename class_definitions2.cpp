#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

enum class Food {WET,DRY,BOTH};
enum class Nose {PINK,BLACK};
enum class Job {COMPANION, SECURITY, RODENT_HUNTER};
struct Cat
{
    char *name;
    Food eats;
    Nose snout;
    Job  works_as_a;
    Cat(char* na,Food F,Nose N,Job J)
    {
        name = (char*) malloc(strlen(na));
        strcpy(name,na);
        eats = F;
        snout = N;
        works_as_a = J;
    }
    Cat(const Cat& orig) 
    {
        printf("in copy constructor\n");
        name = (char*) malloc(strlen(orig.name));
        strcpy(name,orig.name);
        eats = orig.eats;
        snout = orig.snout;
        works_as_a = orig.works_as_a; 
    }
};

std::vector<Cat> cats;

int main(int argc,char *argv[])
{
    Cat A = Cat((char*)"microwave",Food::BOTH,Nose::PINK,Job::COMPANION);
    Cat *B = new Cat((char*)"twist",Food::DRY,Nose::PINK,Job::COMPANION);
    printf("before pushing B\n");
    cats.push_back(*B);
    printf("before pushing A\n");
    cats.push_back(*B);
    Cat& C = *B;
    cats.push_back(C);
    delete B;
    printf("before the return \n");
    return 0;
}
