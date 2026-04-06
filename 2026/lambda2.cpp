#include <algorithm>
#include <vector>
#include <iostream>

int main() {

    std::vector<int> nums = {1, 5, 2, 4, 3};

    // Lambda as a custom comparator
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; 
    });
    for (auto e:nums)
    {
	    std::cout << e << " ";
    }
    std::cout << std::endl;
}

