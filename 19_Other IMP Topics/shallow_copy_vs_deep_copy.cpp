#include <iostream>
using namespace std;
class demo
{

public:
    int a, b, *p;

    demo(int a, int b, int c)
    { // normal constructor
        this->a = a;
        this->b = b;
        p = new int;
        *p = c;
    }
    demo(demo &d)
    { // copy constructor
        this->a = d.a;
        this->b = d.b;

        // assigning new memory to the p. This is deep copy
        p = new int;
        *p = *(d.p);
    }

    void assignvalues(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        *p = c;
    }
    void getvalues()
    {
        cout << "a ->" << a << endl;
        cout << "b ->" << b << endl;
        cout << "p ->" << *p << endl;
    }
};

void shallowcopy()
{
    // shallow copy using assignment operator
    cout << "SHALLOW COPY" << endl;

    demo d1(10, 20, 30);
    demo d2(1, 2, 3); // two objects created

    d2 = d1;
    d2.assignvalues(1, 2, 40); // changing values of d2

    d1.getvalues();
    d2.getvalues();
    // in output , the value of *p becomes 40 for both the objects because it is pointing towards same memory location.
    // value of a and b are different for both the objects;
}
void deepcopy()
{

    cout << "DEEP COPY" << endl;
    // deep copy using copy constructor

    demo d1(10, 20, 30);
    demo d2 = d1; // using copy constructor

    d2.assignvalues(1, 2, 40); // changing values of d2
    d1.getvalues();
    d2.getvalues();
    // in output , the value of *p is different for both the objects because sepertae memory is created for both the pointers.
    // value of a and b are different for both the objects;
}

int main()  
{

    shallowcopy();
    deepcopy();

    return 0;
}