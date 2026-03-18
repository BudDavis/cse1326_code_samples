#include <vector>
#include <iostream>
#include <string>
struct dogRecord
{
	std::string name;
	dogRecord(std::string S):name(S) 
	{
	        std::cout << "creating a dogRecord " << name << " " << this << std::endl;
	}
	~dogRecord()
	{
		std::cout << "deleting a dogRecord " << name << " " <<  this << std::endl;
	}
	dogRecord(const dogRecord &orig)
	{
		name = orig.name;
		std::cout << "copying a dogRecord " << name << " " << this << std::endl;
	}
};
#define DUMP  {for(auto &i:workingDogs) std::cout << "---> " << i.name << " <---" << std::endl;}
int main(int argc,char* argv[])
{
	std::vector<dogRecord> workingDogs = {{"rover"},{"lucky"},{"spike"}};
	//std::vector<dogRecord> workingDogs = {dogRecord("rover"),dogRecord("lucky"),dogRecord("spike")};
#if 0
	std::vector<dogRecord> workingDogs;
	dogRecord a = dogRecord("rover");
	dogRecord b = dogRecord("lucky");
	dogRecord c = dogRecord("spike");
	workingDogs.push_back(a);
	workingDogs.push_back(b);
	workingDogs.push_back(c);
#endif
	DUMP
	std::cout << "------- main " << std::endl;
#if 1

	std::vector<dogRecord>::iterator deleteMe = workingDogs.end();
	std::vector<dogRecord>::iterator i=workingDogs.begin();

        // lets delete "lucky" 
	while ( i!=workingDogs.end() )
	{
		std::cout << "checking " << i->name << std::endl;
		if (i->name=="lucky")
		{
			deleteMe = i;
			std::cout << "storing the iterator for " << i->name << " " << &(*i) << std::endl;
			i = workingDogs.end();
		}
		else
		{
		        i++;
		}
	}
	std::cout << "------------" << std::endl;
	DUMP
        std::cout << "-------------- deleting " << deleteMe->name << " " << &(*i) << std::endl;
	if (deleteMe!=workingDogs.end())
	{
		std::cout << "deleting " << deleteMe->name << std::endl;
		workingDogs.erase(deleteMe);
	}
	DUMP
	std::cout << "end of main" << std::endl;
#endif
}
