#include <cstdio>
class item
{
    public:
        int id;
        int quantity;
        //item(int ID):id(ID){ quantity=0;printf("in item constructor\n");};
        item(){ quantity=0;printf("in item constructor\n");};
};

class resale : public item
{
    // a 'resale item' does not have any tax associated with it
    public:
};

class restricted
{
    // a restricted item has additional restrictions on it being purchased.
    // for this example, lets consider it a purchasers age.
    public:
        unsigned int age;
        restricted() { printf("in restricted constructor\n");};
};

class sale : public item
{
    // a 'sale' item has a sales tax
        static constexpr float tax=0.05;
    public:
        sale(int ID)
        {
            printf("i am in the sale constructor\n");
        }
        sale(){printf("in the no argmument sale constructor\n");};
        //sale(int ID):item(ID)
        //{
        //    printf("in the sale constructor\n");
        //}
};

class tobacco : public restricted, public sale
{
    public:
        tobacco(){ printf("in tobacco constructor\n");};
};

int main(int argc, char *argv[])
{
    printf("main program\n");
    item A;
    //resale B(1);
    printf("creating C\n");
    sale C;
    printf("creating D\n");
    tobacco D;
    return 0;
}
// Things to demonstrate:
//       if there are no arguments to the constructor, the base class is called by the derived class.
//
//       if the base class constructor has no arguments, but the derived class does, then a derived class automatically calls the base class constructor
//
//       multiple inheritance, calling constructors.
