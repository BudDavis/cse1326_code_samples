#include <vector>
#include <iostream>
#include <iterator>
#include <map>

int main(int argc,char* argv[])
{
	std::vector<int> V;
	// old style
	V.push_back(100);
	std::cout << "size is " << V.size() << std::endl;

	auto back_itr = std::back_inserter(V);
	*back_itr = 1;   // this is an output iterator
	back_itr++;
	std::cout << "size is " << V.size() << std::endl;

        // old style // bidirectional
	std::vector<int>::iterator it = V.begin();
	std::cout << *it << std::endl;
	it++;
	it--;
	std::cout << *it << std::endl;

	std::cout << "now for the map " << std::endl;
	std::map<int,std::string> M;
        M.insert({1,"abc"});
	M.insert({2,"def"});
	M.insert({3,"ghi"});
        std::map<int,std::string>::iterator mitr = M.begin();
	std::cout << mitr->second << std::endl;

	// one can also add / subtract 
	auto itr1 = M.begin();
	auto itr2 = itr1++;
	itr2++;
        std::cout << itr2->first << std::endl;
	itr2--;
        std::cout << itr2->first << std::endl;



}
