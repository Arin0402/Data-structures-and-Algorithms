## Day 9

## classes and objects

    - The main difference between a class and a structure is the default access control. In addition to this, classes are typically used for more complex objects that may have member functions and inherit from other classes, while structures are often used for simpler objects that just need to group data together.

    - While structures can still be useful for simple data containers or when interfacing with legacy code, classes offer more flexibility, stronger encapsulation, and better support for object-oriented programming principles. Therefore, in modern C++ development, classes are generally preferred over structures.

    - we can add public and private blocks multiple times in a class

    - this pointer contains the address of the calling object. Its datatype is class name

    
    - class student{

            char name[20];

            // Here it is necessary to use const keyword as it ensures that the parameter received in the function will not be updated
            // It has been done because we are passing a constant string as an actual parameter and we want to make sure that it
            // won't get updated.

            void setstate(const char *n){
                strcpy(name, n);
            }
        }

        student s1;
        s1.setdata("Amit");


## Inline function 

    - It is a keyword 

    - we make function inline to avoid the functoin calls and returns, inorder to save memory and time. When we use inline keyword at starting of any function, then the compiler at the compile time places the code of inline function at its declaration

    - It is like macros in c. a macro is a preprocessor directive that allows you to define a piece of code that can be reused throughout your program. Macros are typically defined using the #define preprocessor directive and can take parameters.
    
    - The disadvantge of using a macro is that it cannot handle more complex programs and we have to declare it in one line only
    - This disadvantage overcame by inline function

    - It is in compiler hands to create a functioon inline or not.
    - If it is not possible to create a function inline, then it is treated as a normal function

    - syntax 

        inline int func(){

        }
    
    - It is just a request to compiler

    *--------------IMP-------------*
    - All the member funcitons of a class are inline by default

    - If any function of a class gives problem to become inline, then we can decalre it outside using the scope resolution operator. Then this function will be treated as a normal function.

        - syntax

            class student {
                void func();
            }

            void student::func(){
                // definition
            }

## Type of member variable

    - Two types

        - instance
        - static

        class data{

            int a;
            static int b;
        }

        int data :: b;

        - we make a variable static when we want a single copy of the varible in the entire class. All the objects share the same variable.

        - instance member variables (like a here) gets the memory when the object is created but what about static variable b?
        - We have to declare it outside so that it can get memory without dependency on any object.

        - static variable can be also accessed using the class name
            cout<< data::b ;

        - scope of static variable is global but its access is limited to class and its members.




