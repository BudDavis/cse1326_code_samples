#include <iostream>
#include <ostream>
#include <string>
void addEndl(std::string S)
{
	std::cout << S << std::endl;
}
void addEndl(int i)
{
	std::cout << i << " " << std::endl;
}
// note you cannot use this on the return value
int main(int argc, char*argv[])
{
	addEndl("hello ");
	addEndl(9);
}

