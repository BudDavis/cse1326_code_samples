#include <iostream>
#include <ostream>
#include <string>
struct License
{
	License()
	{
		std::cout << "License constructor" << std::endl;
	}
	int expirationDate;
	double fee;
	virtual void renew(int months)=0;
	virtual bool takeIntoCustody()=0;
};
struct CityLicense: public License
{
	CityLicense()
	{
		std::cout << "CityLicense constructor " << std::endl;
	}
       void renew(int months)
       {
	       expirationDate=expirationDate+12;
       }
       bool takeIntoCustody()
       {
	       if (expirationDate <=0)
		       return true;
	       else
		       return false;
       }
};

struct CountyLicense: public License
{
        CountyLicense()
	{
		std::cout << "CountyLicense construcor" << std::endl;
	}
       void renew(int months)
       {
	       // county licenses are good for 5 years
	       expirationDate=expirationDate+60;
       }
       bool takeIntoCustody()
       {
	       // county cats are never arrested for
	       // license issues.
	       return true;
       }
};

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

struct barnCat : public Cat, public CountyLicense
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

struct houseCat : public Cat , public CityLicense
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
	std::cout << "arrest this cat " << Lila.takeIntoCustody() << std::endl;
	std::cout << "arrest this cat " << Tiger.takeIntoCustody() << std::endl;
}
