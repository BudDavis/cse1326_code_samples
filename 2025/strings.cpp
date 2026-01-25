#include <iostream>
#include <string>

int main(int argc,char *argv[])
{
    std::string S(5,'1');
    std::cout << "string of 5 Capacity " << S.capacity() << '\n';
    S.reserve(16);
    std::cout << "reserved to 16 Capacity " << S.capacity() << '\n';
    S.resize(5);
    std::cout << "resize to 5 Capacity " << S.capacity() << '\n';
    S.shrink_to_fit();
    std::cout << "shrink to 5 Capacity " << S.capacity() << '\n';
    std::cout << "S is " << S << std::endl;   
    for (unsigned int i=0;i<S.size();i++)
    {
        std::cout << i << " " << S[i] << '\n';
        std::cout << i << " " << S.at(i) << '\n';
    }
    std::cout << "Capacity " << S.capacity() << '\n';
    std::cout << "Max Size " << S.max_size() << '\n';
    S.append("z");
    std::cout << "S append z " << S << std::endl;
    return 0;
}
