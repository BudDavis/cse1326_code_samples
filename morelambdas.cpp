#include <iostream>



int main(int argc, char* argv[])
{
     std::cout << "top" << std::endl;
     int fact = [fact](int i) {
          if (i==1) return 1;
          else return fact(i)*fact(i-1);
     };
     std::count << fact(2) << std::endl;
}
