#include <iostream>
#include <string>
int main(int argc,char *argv[])
{
	std::string A[]={"this","is","an","array","of","strings"};
	for (std::string I:A)
	{
		std::cout << I << std::endl;
	}
	for (std::string &I:A)
	{
		std::cout << I << std::endl;
	}
}
