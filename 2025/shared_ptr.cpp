#include <iostream>
#include <memory> 
#include <string>
#include <vector>

class Dog 
{
public:
    std::string name;
    int catsEaten;
    Dog(std::string N) 
    { 
	    name = N;
	    catsEaten = 0;
	    std::cout << "Dog constructor " << name << std::endl; 
    }
    ~Dog() 
    { 
	    std::cout << "Dog destructor " << name << std::endl; 
    }
    void ateAcat() 
    { 
	    catsEaten++;
	    std::cout << "ateAcat" << std::endl; 
    }
};

typedef std::vector<std::shared_ptr<Dog>> dogVector;

// two lists of dogs.  inside dogs and outside dogs
dogVector outsideDogs;
dogVector insideDogs;

int main(int argc, char* argv[]) 
{
	// this example demonstrates using a shared pointer to clean up

    // buck can be an inside dog and an outside dog
    auto ptr2buck = std::make_shared<Dog>("buck");
    outsideDogs.push_back(ptr2buck);
    insideDogs.push_back(ptr2buck);
    std::cout << "the count for buck is " << ptr2buck.use_count() << std::endl;
    std::cout << std::endl;

    // killer is outside only
    outsideDogs.push_back(std::make_shared<Dog>("killer"));

    // fluffy stays inside
    insideDogs.push_back(std::make_shared<Dog>("fluffy"));

    std::cout << "inside dogs" << std::endl;
    for (auto i:insideDogs)
    {
	    std::cout << '\t' << i->name << " " << i.use_count() << std::endl;
    }
    std::cout << "outside dogs" << std::endl;
    for (auto &i:outsideDogs)
    {
	    std::cout << '\t' << i->name << " " << i.use_count() << std::endl;
    }

    std::cout << "delete all inside dogs" << std::endl;
    insideDogs.clear();
    std::cout << "and get rid of the local ptr to buck" << std::endl;
    ptr2buck.reset();

    std::cout << "inside dogs" << std::endl;
    for (auto &i:insideDogs)
    {
	    std::cout << '\t' << i->name << " " << i.use_count() << std::endl;
    }
    std::cout << "outside dogs" << std::endl;
    for (auto &i:outsideDogs)
    {
	    std::cout << '\t' << i->name << " " << i.use_count() << std::endl;
    }
    std::cout << "end of main program " << std::endl;
    return 0;
}
