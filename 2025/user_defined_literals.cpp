#include <iostream>
#include <chrono>

using namespace std::chrono_literals; 

int main() {
    auto clock = 25ns;
    auto offset = 100ms;
    std::cout << (clock+offset).count() << std::endl;
    return 0;
}
