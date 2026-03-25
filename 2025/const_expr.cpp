#include <iostream>

constexpr int square(int a)
{
	return a*a;
}

int main(int argc, char* argv[])
{
       std::cout << square(2) << std::endl;
       int i;
       // now it is a normal function
       std::cin >> i;
       std::cout << square(i) << std::endl;
}
