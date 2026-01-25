#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string A[]={"a","b","c","d"};
	for (int i=0;i<4;i++)
	{
		std::cout << i << " " << A[i] << std::endl;
	}
	for (std::string i:A)
	{
		std::cout << i << std::endl;
	}
	return 0;
}
