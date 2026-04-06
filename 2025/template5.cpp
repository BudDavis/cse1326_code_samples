#include <iostream>
#include <array>

template <typename T>
	int smallest(T V)
	{
		int smallestIdx = 0;
		for (unsigned int i=0;i<V.size();i++)
		{
		   if (V[smallestIdx] > V[i])
		   { 
			   smallestIdx = i;
		   }	   
		}
		return smallestIdx;
	}

int main (int argc, char* argv[])
{
	std::array<int,3> A = {3,2,1};
	std::cout << smallest(A) << std::endl;
	std::array<char,3> B = {'c','d','a'};
	std::cout << smallest(B) << std::endl;
	std::array<double,3> C = {0.001,0.1,1000.0};
	std::cout << smallest(C) << std::endl;
	return 0;
}
