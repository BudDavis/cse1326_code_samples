#include <iostream>
void a(int& i)
{
	i = 0;
}

void b(int i)
{
	i = 0;
}
// call them both a, and see the error.....
int main(int argc,char* argv[])
{
	int I=100;
	a(I);
	std::cout << I << std::endl;
	I = 100;
	b(I);
	std::cout << I << std::endl;
}
