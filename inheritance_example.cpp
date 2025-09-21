#if 1
#include <cstdio>
class taxable_item
{
    public:
    float taxPercent;
    //taxable_item(float t) { taxPercent=t;};
    virtual float calculate_tax(float x) { printf("in taxable item calculateTax\n"); return x*taxPercent;} ;
    //virtual float calculate_tax(float x) = 0;
};

class resale : public taxable_item
{
    public:
        void do_something() {};
        void only_for_taxable() {};
    resale (float t) { taxPercent=t;};
    //float calculate_tax(float x) override { printf("over riding the base classe\n"); return 0.0;};

};

class cust_item : public taxable_item
{
    public:
};


int main(int argc, char *argv[])
{
        resale  R(0.05);
        //cust_item T;
        T = (cust_item) R;
        printf("tax percent is %f\n",R.taxPercent);
        R.calculate_tax(100.0);
    return 0;
}
#endif
#if 0
// pointers to base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
};

class Rectangle: public Polygon {
  public:
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    int area()
      { return width*height/2; }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
}
#endif
