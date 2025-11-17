#include <iostream>
#include <map>
#include <string>

struct dog
{
    std::string breed;
    int weight;
    std::string color;
    dog(std::string N,int W, std::string C):breed(N),weight(W),color(C){};
};

int main(int argc,char* argv[])
{
    // create a map
    std::map<std::string,std::string> bucket;

    // or another one
    std::map<std::string,int> bucket_of_ints = { {"aaa",100},{"zzz",1},{"m",5} };

    // this one has a key that is not part of the value 
    std::map<std::string,dog> dogs;

    // insert
    dog D(std::string("terrier"),10,std::string("brown"));
    dogs.insert({std::string("rover"),D});

    // or more concisely
    dogs.insert({std::string("little rover"),{std::string("terrier"),5,std::string("brown")}});
    std::cout << "there are " << dogs.size() << " dogs " << std::endl;

    // access
    dog d = dogs.at("rover");
    std::cout << "rover is a " << d.color << " " << d.breed << std::endl;
    // or use d["rover"]
    //
    // remove
    dogs.erase("little rover");
    std::cout << "there are " << dogs.size() << " dogs " << std::endl;
    // put him back
    dogs.insert({std::string("little rover"),{std::string("terrier"),5,std::string("brown")}});

    // process all
    std::cout << "list of dogs" << std::endl;
    for (auto &yapper:dogs)
    {
        // this is where the 'pair' starts showing up...
        std::cout << "\t" << yapper.first << " " << yapper.second.color << std::endl;
    }

    // add some more dogs
    dogs.insert({std::string("spot"),{std::string("mutt"),5,std::string("white with brown spots")}});
    dogs.insert({std::string("tiger"),{std::string("mixed"),5,std::string("mixed")}});
    dogs.insert({std::string("champ"),{std::string("german shephard"),45,std::string("black/brown")}});
    std::cout << "there are " << dogs.size() << " dogs " << std::endl;

    // iterators
    std::map<std::string,dog>::iterator it;
    // (see why auto is so popular)
 
    // find
    it = dogs.find("tiger");
    if (it!=dogs.end())
    {
        std::cout << "found " << std::endl;
        std::cout << '\t' << it->first << std::endl;
        std::cout << '\t' << it->second.breed << std::endl;

    }

    // iterator for loop
    std::cout << "iterator for loop" << std::endl;
    for (auto it=dogs.begin();it!=dogs.end();it++)
    {
        std::cout << '\t' << it->first;
        std::cout << '\t' << it->second.breed << std::endl;
    }
    // also search with [" xxx "]
    return 0;
}
