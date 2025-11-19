#include <iostream>

int main(int argc,char* argv[])
{
	char c[255];
	// enter in 4 or 5 chars
	std::cin.read(c,2);
	std::cout << c << std::endl;
	std::cin.read(c,2);
	std::cout << c << std::endl;
	return 0;
}
