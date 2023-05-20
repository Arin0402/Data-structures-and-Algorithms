## Day 10

# Constructor and destructor

    - A constructor is a special member function in C++ that is used to initialize objects of a class. The constructor has the same name as the class and no return type, and it is called automatically when an object of the class is created.

    - constructor allocates memory to the member variables of the object and initializes them.

    - Why don't we write return type of constructor

        - This is due to security reasons. A constructor returns an object. The return type of constructor is fixed and if the  
            user is given acces to write the return type of constructor, then User can by mistake return anything. So that's why we dont write return type of constructor so that the user cannot modify it.

    - We cannot create member function witrh same name as class name

    - Different methods to call one parameterised constructor

        - data d1 = 10

            OR  

        - data d1(10)

            OR

        - data d1 = data(10)

    - Different methods to call two parameterised constructor

        data d1 = 10 , 20  // This is not allowed
        

        - data d1(10, 20)

            OR

        - data d1 = data(10, 20)

    - Copy constructor should always be passed by reference and not pass by value.

        syntax 

            data(const data &d1){
                
               // initialise the member variables     
            }

# Destructor

    - A destructor is a special member function in C++ that is called automatically when an object of a class is destroyed. The destructor has the same name as the class, preceded by a tilde (~) character, and no return type.

    - The primary purpose of a destructor is to release any resources that were acquired by the object during its lifetime, such as memory allocated using new. The destructor is responsible for freeing these resources to prevent memory leaks.


    -  Example

        MyClass() {
            myPtr = new int(42); 
        }

        ~MyClass() {
            delete myPtr; 
        }

    - No overloading is done in destructor

# Inheritance

    - Inheritance is a fundamental concept in object-oriented programming that allows one class to inherit properties and methods from another class. In C++, classes can be defined to inherit from other classes using the class keyword followed by a colon and the access specifier public, protected, or private, depending on the desired level of access.

    - Inheritance allows for code reuse and simplifies the design of complex software systems by organizing classes into a hierarchy of related classes. It also allows for polymorphism, which means that objects of derived classes can be treated as objects of the base class, enabling the use of dynamic binding and virtual functions.

    - Private is default access specifier

    - Parent class constructor is called first, then the constructor of derived class is called.

    - Parameterised constructor wil by default call the default constructor of the parent class.

    -  A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.

## Modes of Inheritance: 
    
    - There are 3 modes of inheritance.

    - Public Mode -   If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.

    - Protected Mode -   If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become protected in the derived class.
    
    - Private Mode -   If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become Private in the derived class.

## Types Of Inheritance:-

    - Single inheritance -  In single inheritance, a class is allowed to inherit from only one class. i.e. one subclass is inherited by one base class only.


            class B
            { 
                ... .. ... 
            };

            class A: public B
            {
                ... ... ...
            };

    - Multilevel inheritance - In this type of inheritance, a derived class is created from another derived class.

            class C
            { 
                ... .. ... 
            };

            class B:public C
            {
                ... .. ...
            };

            class A: public B
            {
                ... ... ...
            };


    - Multiple inheritance - a class can inherit from more than one class. i.e one subclass is inherited from more than one base class.

            - class B
                { 
                    ... .. ... 
                };

                class C
                {
                    ... .. ...
                };

                class A: public B, public C
                {
                    ... ... ...
                };


    - Hierarchical inheritance -  more than one subclass is inherited from a single base class. i.e. more than one derived class is created from a single base class.

                class A  
                {  
                    // body of the class A.  
                }    
                class B : public A   
                {  
                    // body of class B.  
                }  
                class C : public A  
                {  
                    // body of class C.  
                }   
                class D : public A  
                {  
                    // body of class D.  
                }   

    - Hybrid inheritance - Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple Inheritance.

                class A  
                {  
                    // body of the class A.  
                }    
                class B  
                {  
                    // body of class B.  
                }  
                class C : public A  
                {  
                    // body of class C.  
                }   
                class D : public A, public B  
                {  
                    // body of class D.  
                }   

    - A special case of hybrid inheritance: Multipath inheritance: A derived class with two base classes and these two base classes have one common base class is called multipath inheritance. Ambiguity can arise in this type of inheritance. 


                class ClassA {
                public:
                    int a;
                };
                
                class ClassB : public ClassA {
                public:
                    int b;
                };
                
                class ClassC : public ClassA {
                public:
                    int c;
                };
                
                class ClassD : public ClassB, public ClassC {
                public:
                    int d;
                };


        -  both ClassB and ClassC inherit ClassA, they both have a single copy of ClassA. However Class-D inherits both ClassB and ClassC, therefore Class-D has two copies of ClassA, one from ClassB and another from ClassC. 
        If we need to access the data member of ClassA through the object of Class-D, we must specify the path from which a will be accessed, whether it is from ClassB or ClassC, bcoz compiler can’t differentiate between two copies of ClassA in Class-D.


        There are 2 Ways to Avoid this Ambiguity: 


        1) Avoiding ambiguity using the scope resolution operator: Using the scope resolution operator we can manually specify the path from which data member a will be accessed, as shown in statements 3 and 4, in the above example. 

            -   obj.ClassB::a = 10;       
                obj.ClassC::a = 100;      

        
        Note: Still, there are two copies of ClassA in Class-D.


        2) Avoiding ambiguity using the virtual base class: 

                class ClassA
                {
                public:
                    int a;
                };
                
                class ClassB : virtual public ClassA
                {
                public:
                    int b;
                };
                
                class ClassC : virtual public ClassA
                {
                public:
                    int c;
                };
                
                class ClassD : public ClassB, public ClassC
                {
                public:
                    int d;
                };


                obj.a = 10;     // statement 3
                obj.a = 100;    // statement 4

            - According to the above example, Class-D has only one copy of ClassA, therefore, statement 4 will overwrite the value of a, given in statement 3.

            - output -> 100



### code 1
                
        // parent class
        class A{
            int x;
            public:
                A()
                {
                    cout<<"Constructor of class A\n";
                    x=10;
                }
                A(int a)
                {
                    cout<<"parameterized Constructor of class A\n";
                    x=a;
                }
                void output()
                {
                    cout<<"X = "<<x<<'\t';
                }
        };

        // derived class
        class B:public A{
            int y;
            public:
                B()
                {
                    cout<<"constructor of class B\n";
                    y=20;
                }
                B(int a, int b)
                {
                    cout<<"parameterized Constructor of class B\n";
                    y=b;
                }
                void output()
                {
                    A::output();
                    cout<<"Y = "<<y<<endl;
                }
        };

        int main()
        {
            B b1;
            b1.output();
            cout<<endl;
            
            B b2(100,200);
            b2.output();            
        }


### code 2    

        class A{
            int x;
            public:
                A()
                {
                    cout<<"Constructor of class A\n";
                    x=10;
                }
                A(int a)
                {
                    cout<<"parameterized Constructor of class A\n";
                    x=a;
                }
                void output()
                {
                    cout<<"X = "<<x<<'\t';
                }
        };

        class B:public A{
            int y;
            public:
                B()
                {
                    cout<<"constructor of class B\n";
                    y=20;
                }
                B(int a, int b):A(a) // parameterised constructor of a being called
                {
                    cout<<"parameterized Constructor of class B\n";
                    y=b;
                }
                void output()
                {
                    A::output();
                    cout<<"Y = "<<y<<'\t';
                }
        };

        class C:public B{
            int z;
            public:
                C():B()
                {
                    z=30;
                }
                C(int a, int b, int c):B(a,b) // parameterised constructor of b being called
                {   
                    cout<<"parameterized Constructor of class C\n";
                    z=c;
                }
                void output()
                {
                    B::output();
                    cout<<"Z = "<<z<<endl;
                }
        };
        int main()
        {
            C c1(100,200,300);
            c1.output();
            return 0;
        }

### code 3

        class Array{
            int *arr;
            int n;
            public:
                Array()
                {
                    arr=NULL;
                    n=0;
                }
                Array(int n1)
                {
                    n=n1;
                    arr=new int[n];        //dynamic memory
                }
                Array(const Array &r)
                {   
                    cout<< "Copy constructor called"<<endl;
                    n=r.n;
                    arr=new int[n];
                    //deep copy
                    for(int i=0;i<n;i++)
                    {
                        arr[i]=r.arr[i];
                    }
                }
                int get_data()
                {
                    for(int i=0;i<n;i++)
                    {
                        cout<<"Enter value of "<<i+1<<"element:";
                        cin>>arr[i];
                    }
                }
                void output()
                {
                    for(int i=0;i<n;i++)
                    {
                        cout<<arr[i]<<' ';
                    }
                    cout<<endl;
                }
                void free()
                {
                    delete []arr;
                }
        };
        int main()
        {
            Array a1=5;
            a1.get_data();    //[10,20,30,40,50]
            cout<<"a1=";
            a1.output();        //[10,20,30,40,50]
            
            // copy constructor
            Array a2=a1;
            
            cout<<"a2=";
            a2.output();        //[10,20,30,40,50]
        
            a2.get_data();        //[100,200,300,400,500]
            cout<<"a1=";
            a1.output();        //[100,200,300,400,500]
            cout<<"a2=";
            a2.output();        //[100,200,300,400,500]
        
            a1.free();
            a2.free();
            return 0;
        }

# Abstraction

    - Data abstraction is the property by virtue of which only the essential details are displayed to the user.
        The trival or the non essential units are not displayed to the user. It is the process of only identifying only the required characteristics of an object while ignoring the irrelevant details.
    
    - In C++, abstraction is implemented using abstract classes and pure virtual functions.

# Encapsulation

    - Encapsulation is a fundamental principle in object-oriented programming (OOP) that involves bundling data and methods together within a class and controlling their access through well-defined interfaces.

    - In encapsulation, an object's data (attributes or properties) and the methods (functions or behaviors) that operate on that data are grouped together as a single unit. The data is typically declared as private or protected, meaning it is not directly accessible from outside the class. The methods, on the other hand, are declared as public or private, specifying their accessibility.

    - The key aspects of encapsulation are:

        - Data Hiding: Encapsulation hides the internal state of an object by making the data private or protected. This prevents direct access and modification of the data from external sources. 

        - Access Control: Encapsulation allows for controlling access to the internal components of an object. By declaring certain data or methods as private or protected, you restrict direct access to them from external sources. This provides a level of security and prevents unintended modifications or misuse of the object's internals.

        - Modularity and Reusability: Encapsulation promotes modularity by encapsulating related data and methods into self-contained classes. This makes it easier to manage and maintain code, as changes to one class do not affect other parts of the program. Encapsulated classes can also be reused in different contexts, as their internal implementation is hidden and the interaction is performed through well-defined interfaces.

    - Overall, encapsulation helps in achieving data abstraction, information hiding, code organization, and improved code maintainability. It ensures that the implementation details are hidden and only the necessary information and operations are exposed, promoting a more robust and secure design in object-oriented programming.


    - Abstraction is the thought process and encapsuation is the implementation.