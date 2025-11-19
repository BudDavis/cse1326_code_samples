#include <fstream>
#include <iostream>

int main(int argc,char* argv[])
{
	std::fstream f("words_alpha.txt",std::ios::in);
	std::string word;
	int count=0;
        while (f>>word)
	{
		count++;
	}
        std::cout << "there are " << count << " words." << std::endl;
	return 0;
}
