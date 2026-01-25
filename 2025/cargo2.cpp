#include <iostream>
struct Cargo
{
	// this class is used to track cargo
	// being transported by a truck
	double weight;
	double height;
	Cargo(int X)
	{
		weight = X;
		height = 1;
	}
	double operator + (Cargo &C)
	{
		return C.weight + weight;
	}	
};


int main(int arc,char *argv[])
{
	Cargo Truck(10);
	Cargo BiggerTruck(100);
	std::cout << Truck+BiggerTruck << std::endl;
	return 0;
}
