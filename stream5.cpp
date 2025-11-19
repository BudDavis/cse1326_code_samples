#include <sstream>
#include <iostream>


int main(int argc, char* argv[])
{
	// the can be input or output, or both
	// this one is both
	std::stringstream SS;
	// put something in the stream
	SS << "octal is " << std::oct << 9;
	// get it out as a string
	std::cout << SS.str() << std::endl;
	// other way
	std::string S="hex is 0x09";
	SS.str(S);
	std::cout << SS.str() << std::endl;
	return 0;
}
