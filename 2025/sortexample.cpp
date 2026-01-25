// g++ sortexample.cpp -Wall -std=gnu++17 -g
#include <algorithm>
#include <vector>
#include <stdio.h>
class  plywood
{
    public:
    double w;
    double h;
    double thickness;
    // one of many kinds of constructors
    plywood(double W, double H, double T):w(W),h(H),thickness(T){};
};

bool compare_area (plywood a, plywood b)
{
    return  (a.w*a.h) < (b.w*b.h);
}

int main(int argc, char* argv[])
{
    std::vector<plywood> pile_of_wood = {plywood(1.0,1.0,0.5),plywood(0.5,0.5,0.25)};
    sort(pile_of_wood.begin(),pile_of_wood.end(),compare_area); 
    for ( auto piece:pile_of_wood)
    {
        printf(" %f %f \n",piece.w,piece.h);
    }
    return 0;
}
