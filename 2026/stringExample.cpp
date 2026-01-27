#include <iostream>
#include <string>
//g++ -std=gnu++17 stringExample.cpp  -Wall
int main(int argc, char* argv[])
{
	std::string S = "abc";
	std::string A = std::string("def");
	std::cout << S << A << std::endl;
	A = "hello";
	std::cout << A << std::endl;
	std::cout << A << " " << typeid(A).name()  << std::endl;
	auto B = "what am i?";
	std::cout << B << " " << typeid(B).name()  << std::endl;
	int L = 0;
	std::cout << typeid(L).name() << std::endl;
	return 0;
}
