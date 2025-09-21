#include <vector>
#include <stdio.h>

std::vector<int> V;


int main (int argc, char* argv[])
{
    V={7,8,9};
    printf("number in vector is %ld\n",V.size());
    for ( auto v:V )
    {
        printf("%d\n",v);
    }

    V.clear();
    V.push_back(10);
    V.push_back(11);

    printf("number in vector is %ld\n",V.size());
    for ( auto v:V )
    {
        printf("%d\n",v);
    }
    return 0;
}
