#include <iostream>
#include <string>
// lots of issues with this code:
// show the difference between sales_price being a pointer and a copy
// also, 'not very OO'......
struct sales_price
{
	float coffee;
	float latte;
	float greenStuff; // ?? matcha ??
	float tea;
	sales_price(float _c,float _l,float _g,float _t):coffee(_c),latte(_l),greenStuff(_g),tea(1.23){}
	sales_price(){coffee=0.0;latte=0.0;greenStuff=0.0,tea=0.0;}
};
struct customer
{
	sales_price  Menu;  // this is the prices that apply to this customer
	std::string name;
	int table;          // the table in which the customer resides
        customer(sales_price _m,std::string _n,int _t)
	{
		Menu = _m;
		name = _n;
		table = _t;
	}
};
void print(customer C)
{
	std::cout << C.name << " " << C.Menu.tea << std::endl;
}
int main(int argc, char *argv[])
{
	// create the menu
	sales_price Menu{1.00,2.10,3.00,1.50}; // one of many ways to initialize a class
	
        customer C1 = customer(Menu,"billy bob thornton",5);
        customer C2 = customer(Menu,"ted nugent",4);
        print(C1);
	print(C2);
}
