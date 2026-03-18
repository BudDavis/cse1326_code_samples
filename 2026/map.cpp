#include <iostream>
#include <map>

//map<Key, Value, Comparator, Allocator>
int main(int argc, char*argv[])
{
	std::map<int,std::string,std::less<int>,std::allocator<int>> M;
	M.insert({100,"one hundred"});
	M.insert({200,"two hundred"});
	// [] will insert a 0 if you search and it is not found
	//
	//
	// talk about std::pair
	// find()
	for (const auto& pair : M) 
	{
                std::cout << pair.first << std::endl; 
        }

	for (const auto& pair : M) 
	{
                std::cout << pair.second << std::endl; 
        }
}
