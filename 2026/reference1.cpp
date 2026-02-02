#include <iostream>

int main(int argc, char *argv[])
{
	int A = 100;
	int& Aref=A;
	int* Aptr=&A;
	int B = 200;
	std::cout << A << " " <<  Aref << " " << *Aptr << std::endl;
	Aref = B; // look over closely
	std::cout << A << " " <<  Aref << " " << *Aptr << std::endl;
	/* the output
100 100 100
200 200 200
        */
}
