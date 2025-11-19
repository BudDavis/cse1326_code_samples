#include <iostream>
#include <string>

// Shows using some of the manipulators in output

int main(int argc,char* argv[])
{
	std::string S="abc";
	double d=4.141515;
	bool b=true;
	std::cout << std::fixed << d << '\n';
	std::cout << std::scientific << d << '\n';
	std::cout << std::boolalpha << b << '\n';
	std::cout << !b << std::endl;

	return 0;
}
