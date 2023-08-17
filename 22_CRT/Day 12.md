## Day 12

    - >> is called insertion operator
    - << is called extraction operator

# friend function


    - a friend function is a function that is granted access to the private and protected members of a class, even though it is not a member of that class. Friend functions are declared in the class that is granting access to its members, but they are defined outside of the class.

    -  For example, you might have a function that needs to perform some complex calculation using the private data members of a class, but it doesn't actually modify any of those data members.

    - It is not necessary that friend fuction should be a member function of a class

        for ex - getline(cin, str)

    - we can also declare whole class as friend. 

        for ex- if we declare class A as a friend of b, then all the functions of A can access the members of class B


## Demonstration

### code 1

    - sum is the member function of class A and friend function of class B

    #include<iostream>
    using namespace std;

    class B;
    class A{
        int x;
        public:
            A(int x1=0)
            {
                x=x1;
            }
            int sum(B);        //member function declaration
    };

    class B{
        int y;
        public:
            B(int y1)
            {
                y=y1;
            }
            friend int A::sum(B);    //friend function declaration
        
    };

    int A::sum(B b1)    //function definition
    {
        return x+b1.y;
    }

    int main()
    {
        A a1=10;
        B b1=20;
        cout<<a1.sum(b1);
        return 0;
    }


    - The syntax of declaration is like
        - member class // class A
        - friend class // class B
        - friend function declaration // sum


### code 2

    #include<iostream>
    using namespace std;

    class B;

    class A{
        int x;
        public:
            A(int x1=0)
            {
                x=x1;
            }
            friend int sum(A,B);        //friend function declaration
    };

    class B{
        int y;
        public:
            B(int y1)
            {
                y=y1;
            }
            friend int sum(A,B);    //friend function declaration
        
    };

    int sum(A a1,B b1)    //function definition
    {
        return a1.x+b1.y;
    }
    int main()
    {
        A a1=10;
        B b1=20;
        cout<<sum(a1,b1);
        return 0;
    }


# Operator overloading of <<    >>

    #include<iostream>
    using namespace std;

    class data{
        
        int a;
        float b;
        
        public:
        
            data(int a1, float b1)
            {
                a=a1;
                b=b1;
            }
            friend ostream& operator<<( ostream&, data &);
            friend istream & operator>>( istream&, data &);
    };

    ostream & operator<<(ostream& out,data &d)
    {
        out<<d.a<<' '<<d.b<<endl;
        return out;
    }

    istream & operator>>(istream& in,data &d)
    {
        cout<<"Enter int:";
        cin>>d.a;
        cout<<"Enter float:";
        cin>>d.b;
    }

    int main()
    {
        data d1(10,5.4);
        
        // when we need to use cout with user defined object
        cout << d1;
        cin >> d1;
        cout << d1;
    }
    

    - !-----------------------IMP------------------!
    - Here << is a function (operator overloading) which takes two arguments. one is cout and other one is user defined data type

    - We could also implement the operator overloading function in the ostream class if we could modify the class but we cannot.

    - We have declared << as the friend functtion of ONLY class data because for printing, we only need the member varibales of class Data. ( We are declaring this as friend function because we need to acces the private member variables of class Data, otherwise we could also have declared it as a normal function)

    - That's why we haven't declared << as friend function for class ostream and the matter of fact is that we cannot modify the class.

    - we are returning the refrence to the ostream and istream class objects because it is more efficient rather than returning the new object. Returning refrence helps to print multiple objects in chain

        - for ex

            cout << d1 << d2;

            - The first << executes and returns the refrence to the same cout that was sent as parameter. 
            - Then the second << executes and prints d2.
        

# Templates

    - In C++, templates are a way to write generic code that can work with different types of data. A template is a code blueprint or a recipe for creating functions or classes that work with different data types without having to write separate implementations for each type.

    - Scope of Typename T is limited to one bracket pair that comes after only


## demonstration

### code 1

    #include<iostream>
    using namespace std;

    template <typename T>
    T sum(T a, T b)
    {
        return a+b;
    }

    int main()
    {
        cout<<sum(10,20)<<endl;
        cout<<sum(5.4,7.2)<<endl;
        cout<<sum(10.25f,7.5f)<<endl;
    }    

    - NOTE -> if the compiler find the function the with same argument types as the calling function, then that function will be called

        
        #include<iostream>
        using namespace std;

        template <typename T>
        T sum(T a, T b)
        {
            return a+b;
        }
        int sum(int a, int b)
        {
            cout<<"Int ";
            return a+b;
        }

        int main()
        {
            cout<<sum(10,20)<<endl;
            cout<<sum(5.4,7.2)<<endl;
            cout<<sum(10.25f,7.5f)<<endl;
        }

        output ->   Int 30
                    12.6
                    17.75

### code 2

    - Template with two types of data
    - we are returning double beacuse double can store int, float and double. i.e all in one

    #include<iostream>
    using namespace std;

    template <typename T1, typename T2>

    double sum(T1 a, T2 b)
    {
        return a+b;
    }

    int main()
    {
        cout<<sum(10,7)<<endl;
        cout<<sum(5,7.2f)<<endl;
        cout<<sum(10.25,7.5f)<<endl;
    }

### code 3

    - Basically this is how all the stl data structures work like vector, map, set etc.

    #include<iostream>
    using namespace std;

    template <typename T>
    class Array{
        T arr[10];
        int n;
        public:
            void input()
            {
                cout<<"Enter no of elements:";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    cout<<"Enter value of "<<i+1<<" element:";
                    cin>>arr[i];
                }
            }
            void output();
    };

    template <typename T>
    void Array<T>::output()
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int main()
    {
        Array <int>a1;
        Array<float> a2;
        a1.input();
        a2.input();
        a1.output();
        a2.output();
        return 0;
    }