### Day 5

    1. #include <iostream>

        In C++, the #include <iostream> directive is a preprocessor directive that instructs the compiler to include the declarations of the standard input/output stream objects (cin, cout, cerr, etc.) in your program.

        The iostream header file defines the input/output stream classes, such as istream and ostream, and the standard stream objects (cin, cout, cerr, etc.), as well as various input/output manipulators (endl, setw, etc.).

        When you include the iostream header file in your program, you get access to these standard stream objects and manipulators, which you can use to perform input/output operations in your program.

        In the code std::cout << "Hello, world!" << std::endl;, std:: is a namespace qualifier that indicates that cout and endl are defined in the std namespace.

        The std namespace is a namespace defined by the C++ standard library that contains the definitions of all the standard library components, such as input/output operations (cout, cin, cerr, etc.), containers (vector, list, map, etc.), algorithms (sort, find, etc.), and more.

        When you include the iostream header file in your code, the cout and endl objects are declared in the std namespace. To use these objects, you need to prefix their names with the std:: qualifier to indicate that they belong to the std namespace.

        The cout object is an instance of the ostream class, which is defined in the std namespace. This means that the cout object is technically a member of the ostream class, but it's also part of the std namespace.

        To use cout in your code, you need to qualify its name with the std:: prefix to indicate that it belongs to the std namespace. This is because the std namespace contains many other classes, functions, and objects, and it's important to avoid naming conflicts.

        For example, when you use the std::cout expression to output data to the console, the std:: part tells the compiler to look for the cout object inside the std namespace. This ensures that the correct cout object is used, even if you have other variables or functions with the same name in your code.

        So, while cout is defined as a member of the ostream class, it's typically accessed through the std namespace using the std::cout expression.


        - cin is input stream object
        - cout is output stream object
        -  >> is input stream operator
        - << is output stream operator

    2. print the pattern without using for loop

        5 4 3 2 1 1 2 3 4 5

        void print(int n){

            if(n == 0) return;

            cout<< n;
            print(n-1);
            cout<< n
        }

    3. print the lucas series

        int lucas(int n){

            if(n <= 0) return 0;
            if(n == 1) return 1;

            return lucas(n-1) + lucas(n-2) + lucas(n-3);
        }

    4. Polymorphism -> many forms

        The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism is a person who at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee.

        - Types

            - Compile time

                - Function Overloading

                    When there are multiple functions with the same name but different parameters, then the functions are said to be overloaded, hence this is known as Function Overloading.
                
                - operator overloading

                    C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can make use of the addition operator (+) for string class to concatenate two strings. We know that the task of this operator is to add two operands. So a single operator ‘+’, when placed between integer operands, adds them and when placed between string operands, concatenates them. 

            - Run time

                - virtiual functions
                - function overriding

        - (---------- From GFG---------)
        https://www.geeksforgeeks.org/cpp-polymorphism/
