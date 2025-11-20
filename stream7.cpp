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
        words.insert( {word,word.size() } );
		count++;
		// add it to listBySize, and put it in the vector returned
        std::map<int,wordList>::iterator itr;
        itr = listBySize.find( word.size() );
        if ( itr!=listBySize.end() )
        {
            // it is found
            itr->second.push_back ( word );
        }
        else
        {
            // need to insert it
            wordList V;
            V.push_back(word);
            listBySize.insert ( { word.size() ,V } );
        }
	}
    std::cout << "the size of words is " << words.size() << std::endl;
	// look something up
	//
	// (given a word, you can provide a list of all other words of the same length)
        std::cout << "there are " << count << " words." << std::endl;
    std::string lookFor = "night";

    // search in words to get the size
    std::map<std::string,int>::iterator jtr;
    jtr = words.find(lookFor);
    if (jtr!=words.end())
    {
        // first is string, second is size
        std::map<int,wordList>::iterator itr;
        itr = listBySize.find(jtr->second);
        if (itr!=listBySize.end())
        {
            for (auto i:itr->second)
            {
                std::cout << i << std::endl;
            }
        }
    }
    else
    {
        std::cout << "could not find " << lookFor << std::endl;
    }

	return 0;
}
