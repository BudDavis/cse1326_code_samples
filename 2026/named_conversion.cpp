#include <iostream>
// This example shows use of named conversions
//
//
int main(int argc,char* argv[])
{
	// const_cast removes the const
	const int& I = 33;
	int& J = const_cast<int&>(I);
	J++;
	std::cout << I << std::endl;
        // static_cast
	double A = 3.14;
	int B = static_cast<int>(A);
	std::cout << B << std::endl;
//////////////////////////////////////////////////////////////
	class base
	{
		public:
		int n;
	};
	class derived: public base
	{
		public:
		int o;
	};
        base *C = new base{10};
        derived *D = new derived{11,12};
        std::cout << C->n << "  " << D->n << "  " << D->o << std::endl;	
	// allways safe, to go up (towards the base)
        base E = static_cast<derived>(*D);	
	std::cout << "statc cast " << E.n << std::endl; 
//////////////////////////////////////////////////////////////
	// reinterpret_cast
	//         pointer to pointer
	char ch[8] = { 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
	int *in = (int*) malloc(sizeof(int));
	*in = 999;
        in = reinterpret_cast<int*>(ch);
	std::cout << "reinterpret " << *in << std::endl;
	
        // dynamic_cast  (done at runtime)
	//         can raise exceptions...
	//base *newBase = new base{500};
	//derived newDerived = dynamic_cast<derived*>(newBase);
	//std::cout << newDerived.n << std::endl;
}
