#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
//g++ -std=gnu++17 stringExample2.cpp  -Wall
int main(int argc, char* argv[])
{
	std::string S = "abc";
	// size
	std::cout << "size is " << S.size() << std::endl;
	// + operator
	std::string T = "def";
	std::string U;
	U = S + T;
	std::cout << U.size() << " " << U << std::endl;
	const char *a;
	a = U.c_str(); // read only, null terminated
	printf("%ld %s\n",strlen(a),a);
	return 0;
}
