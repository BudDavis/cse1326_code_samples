#include <iostream>
#include <set>
int main(int argc, char* argv[])
{
	std::set<int,std::less<int>,std::allocator<int>> S;

	S.insert(1024);
	S.insert(2048);
	auto itr =  S.find(0);
	if (itr==S.end())
	{
		std::cout << "did not find 0 " << std::endl;
	}
	else
	{
		std::cout << "did find 0 " << std::endl;
	}
	itr =  S.find(1024);
	if (itr==S.end())
	{
		std::cout << "did not find 1024 " << std::endl;
	}
	else
	{
		std::cout << "did find 1024 " << std::endl;
	}


}

