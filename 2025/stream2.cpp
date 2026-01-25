#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	int a;
	int b;
	std::cout << "give me 2 numbers" << std::endl;
    std::cin >> a;
	std::cin >> b;
	std::cout << "std out " << b << " " << a << '\n';
	std::cerr << "std err " << b << " " << a << '\n';
	std::clog << "std log " << b << " " << a << '\n';
	return 0;
}
