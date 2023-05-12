## Day 11

    - istream and ostream classes are the child class of the ios class
    - these three classes have been put in the iostream file

    - ifstream is the child class of istream class
    - ofstream is the child class of ostream class
    - Both the classes have been put in the fstream class


## Object slicing

    class A{
        
        int x;
        
    }

    class B: public A{
        
        int y;

        assign( z ){
            x = z;
            y = z;            
        }

    }

    main(){

        A a;
        B b;

        - Here a will have x
        - b will have x and y both (object of A will be created in b)

        - Now object b can be assigned to a but the vice versa is not possible

            - This is correct, x in a will take the value of x in b only. y will be ignored.
                a = b 

            - This is not correct as y is not present in a so assignment cannot be done
                b = a 
    }

    - So in object slicing, 

        parent.object = child.object  (This is allowed)
        child.object  = parent.object (This is not allowed)

    
## Parent and child class relation in terms of pointer


    - Taking the example

        class A{
            
            int x;

            void func(){

            }
            
        }

        class B: public A{
            
            int y;

            void func(){

            }

        }


        A *p

        p = &a (This is correct) (parent pointer can take the address of the parent's object)
        p = &b (This is correct) (parent pointer can also take the address of the child's object)

        - In this case p = &b, what happens is p the pointer of A type and it gets the address of B type. 
        - so at the compile time the type of p is A and at the run time, the type becomes B.
        
        - so if we write like this

            A *p
            p = &b

            p -> func();

            - Now which function will p call, of class A or class B  ? 
            - The answer is that p will call the function of class A, as at the compile time the type of p is A and all the binding is done at compile time. This is compile time binding
            - So at the run time, when type of p becomes B, it does not matter because all the binding has been done at the compile time

            - we unsderstand more in dynamic binding

        -   B *p

            p = &b (This is correct)
            p = &a (This will result in a compilation error because Child has additional members that are not present in Parent, and the Child pointer cannot access those members through a Parent object.)

        - So in summary     

            - Parent pointer = &Child.object ( This is allowed)
            - Child pointer = &Parent.objext (This is not allowed)

## Dynamic binding (Run time polymorphism)

    - Also known as late binding    
    - Compile time binding is called early binding
    
    - In compile time binding, binding of pointers and objects to the member variables is done at compile time whereas it is done at run time in run time binding.

    - We decide at run time that which functions and memnber variables will be called

    - if Compile time binding , then the program compilation is slower but the execution is faster
    - if Run time binding , then the program compilation is faster but the execution is slower

    - Taking the same example as above
    
        class A{
            
            int x;

            void func(){

            }
            
        }

        class B: public A{
            
            int y;

            void func(){

            }

        }

        main(){

            B b;
            A *p;
            p = &b;

            p -> func(); // This will func() of class A due to compile time binding. At the run time the type of p is B
            
        }

        - Now for runtime binding, we are adding virtual infront of func() in parent class. 

            - * ------------------IMP-----------------*
            - using virtual keyword, what will happen is that this parent class function will refuse to do binding at the compile time. So by doung this we can call the func() of child class using p as at the run time type of p becomes B
        

            class A{
                
                int x;

                virtual void func(){

                }
                
            }

            class B: public A{
                
                int y;

                void func(){

                }

            }

            main(){

                B b;
                A *p;
                p = &b; // OR p = new B();

                p -> func(); // This will func() of class B due to run time binding. At the run time the type of p is B
                
            }
        
        - Inheritance and function overriding is necessary for dynamic binding

## Very good example of run time binding

    #include<iostream>
    #include<string.h>
    using namespace std;

    class mobile{    //abstract class
        public:
            virtual void network()=0;    //pure virtual function
    };
    class BSNL:public mobile{
        public:
            void network()
            {
                cout<<"Class BSNL\n";
            }
    };
    class Airtel:public mobile{
        public:
            void network()
            {
                cout<<"Class Airtel\n";
            }
    };
    int main()
    {
        mobile *p;
        int n;
        cout<<"1. BSNL\n2. Airtel\n";
        cin>>n;
        if(n==1)
            p=new BSNL;
        else
            p=new Airtel;
        p->network();
    }


    - Here newtwork() is pure virtual function. A pure virtual function in C++ is a virtual function that has no implementation in the base class and must be implemented in a derived class. The syntax for declaring a pure virtual function in C++ is to append the function declaration with the = 0 pure specifier.

    - here class mobile is a Abstract class

        - In C++, an abstract class is a class that cannot be instantiated because it contains one or more pure virtual functions. An abstract class is also known as an "abstract base class" or an "ABC".
        
        - An abstract class serves as a base class for other classes that inherit from it and provides a common interface for those classes.
        
        - Because the pure virtual functions have no implementation in the abstract class, the derived classes must provide their own implementation to be instantiated.

        - if a class contains atleast one virtual function then it becomes the abstract class.


## operator overloading

    - Operator overloading in C++ allows you to define the behavior of operators when they are used with user-defined types (objects) as operands. This allows you to extend the functionality of operators to work with your own classes and objects.

    - Rules

        - one operand must bew user defined
        - precedency and associativity of the operator will not change
        - ::, size of, *, . , ->   (These operators will not be overloaded)


    - unary operators 

        -  +    -   ++  --  size of     typecasting

        - +  and - are sign change operators

## Demonstraction

    #include<iostream>
    #include<string.h>
    using namespace std;

    class Data{
        
        int a;
        
        public:
            Data(int a1=0)
            {
                a=a1;
            }
            Data signchange()
            {
                Data temp;
                temp.a=a*-1;
                return temp;
            }
            Data operator-()
            {
                Data temp;
                temp.a=a*-1;
                return temp;
            }
            void output()
            {
                cout<<a<<endl;
            }
            Data inc()
            {
                Data temp;
                a=a+1;
                temp.a=a;
                return temp;
            }
            Data operator ++()    //pre
            {
                Data temp;
                a=a+1;
                temp.a=a;
                return temp;
            }
            Data operator++(int)    //post (We write int in bracket to denote that it is post increment)
            {
                Data temp;
                temp.a=a;
                a=a+1;
                return temp;
            }
            explicit operator int()
            {
                return a;
            }
    };

    int main()
    {
        Data d1 = 10;
        Data d2;

        *------------------sign change overloading---------------------*
        // d2 = d1.signchange();
        d2 = -d1;
        d1.output();    //10
        d2.output();    //-10


        *------------------increment-decrement overloading---------------------*
        //d2 = d1.inc();
        d2 = ++d1;
        d1.output();        //11
        d2.output();        //11
        
        d2 = d1++;
        d1.output();        //12
        d2.output();        //11
        

        *------------------typecasting overloading---------------------*
        //d1=100;
        d1 = Data(100);
        d1.output();
        
        int n;
        n=int(d1);
        cout<<n<<endl;
    }








