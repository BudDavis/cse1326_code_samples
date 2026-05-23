//  g++ -std=gnu++20 spaceshipoperator.cpp  -Wall
#include <iostream>

int main(int argc, char* argv[])
{
	if (('a' <=> 'a')==0)
	    std::printf("%s\n","equal");
}
