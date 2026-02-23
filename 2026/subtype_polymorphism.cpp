#include <iostream>
#include <ostream>
#include <string>
struct Cat
{
        int numMice;
	int hoursSlept;
	void status()
	{
		std::cout << "this cat has eaten " << numMice << " and slept " << hoursSlept << std::endl;
	}
	virtual void worksHours (int n) = 0;
	//virtual void worksHours (int n)
	//{
	//}
	Cat()
	{
		std::cout << "Cat constructor " << std::endl;
		numMice=0;
		hoursSlept=0;
	}
	~Cat()
	{
		std::cout << "Cat destructor " << std::endl;
	}
};

struct barnCat : public Cat
{
	void worksHours(int n)
	{
		numMice+=n;      // eats one mouse an hour
		hoursSlept+=n/2; // sleeps half of the time, after the first hour
	}
	barnCat()
	{
		std::cout << "barnCat constructor " << std::endl;
	}
	~barnCat()
	{
		std::cout << "barnCat destructor " << std::endl;
	}
};

struct houseCat : public Cat
{
	void worksHours(int n)
	{
		// does not eat mice
		hoursSlept+=n;
	}
	houseCat()
	{
		std::cout << "houseCat constructor" << std::endl;
	}
	~houseCat()
	{
		std::cout << "houseCat destructor" << std::endl;
	}
};

int main(int argc, char*argv[])
{
	houseCat Lila;
	barnCat Tiger;
	Lila.worksHours(1);
	Tiger.worksHours(2);
	Lila.status();
	Tiger.status();
}
