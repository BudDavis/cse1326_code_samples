#include <iostream>
#include <vector>

template <typename T>
	T sum(std::vector<T> v)
	{
		T total=0;
		for (T i:v)
		{
			total+=i;
		}
		return total;
	}

int main (int argc, char* argv[])
{
	std::vector<int> x={1,2};
	std::cout << sum<int>(x) << std::endl;
	std::vector<float> f = {1.0,0.100};
	std::cout << sum<float>(f) << std::endl;
	return 0;
}
