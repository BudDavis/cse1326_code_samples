#if 0
#include <boost/smart_ptr/scoped_ptr.hpp> 
#include <iostream>


int main(int argc,char* argv[])
{
    std::cout << "hello\n"; 
    return 0;
}
#else
#include <boost/scoped_ptr.hpp>
#include <iostream>

struct Shoe 
{
    ~Shoe() 
    { 
        std::cout << "Buckle my shoe\n"; 
    } 
};

class MyClass {
    boost::scoped_ptr<int> ptr;
  public:
    MyClass() : ptr(new int) 
    { 
        *ptr = 0; 
    }
    int add_one() 
    { 
        return ++*ptr; 
    }
};

int main()
{
    boost::scoped_ptr<Shoe> x(new Shoe);
    MyClass my_instance;
    std::cout << my_instance.add_one() << '\n';
    std::cout << my_instance.add_one() << '\n';
}
#endif
