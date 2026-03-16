#include <array>
#include <iostream>

int main(int argc,char* argv[])
{
	const unsigned int N = 5;
	std::array<int,N> A;
	// look at this syntax....
	std::get<0>(A) = 100;
	for (auto k:A)
	  std::cout << k << std::endl;
}
