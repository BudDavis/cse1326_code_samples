#include <fstream>
#include <iostream>
#include <map>
#include <vector>

// read in all the words, and keep track of the length of each one

// this datastructure stores the words, and the count of how many in
// a map
//        key        value
std::map<std::string,int> words;

// for a given length, this map stores a list of the words of a given
// length
typedef std::vector<std::string> wordList;
//       key, value
std::map<int,wordList> listBySize;

// Not saying this is a practical demonstration, but it does show
// some C++ features.

int main(int argc,char* argv[])
{
	std::fstream f("words_alpha.txt",std::ios::in);
	std::string word;
	int count=0;
	// read in the file
        while (f>>word)
	{
		// put it in words, along with the length 
		count++;
		// add it to listBySize, and put it in the vector returned
	}
	// look something up
	//
	// (given a word, you can provide a list of all other words of the same length)
        std::cout << "there are " << count << " words." << std::endl;
	return 0;
}
