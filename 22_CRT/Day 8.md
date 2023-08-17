## Day 8

## Strings

    - character arrays
        - we need to know the size before hand
        - Larger size required for operations(concetation and append)
        - No terminating extra character

    - Strings
        - No need to know the size before hand
        - Performing operations like concetation and append is easier
        - terminated with a special '\0' character

    - Memory repersentation

        - a string is represented in memory as a contiguous block of characters, followed by a null character ('\0') that indicates the end of the string. This representation is known as a null-terminated string.

            | 'H' | 'e' | 'l' | 'l' | 'o' | '\0' |

        - a string is represented as an array of characters. The characters in the array are stored in contiguous memory locations,  although a string is represented as an array of characters, it is not the same thing as a C-style character array. Strings in C++ are dynamic data structures that can be resized and modified at runtime, while C-style character arrays have a fixed size and cannot be resized. Additionally, the string class provides many useful functions for working with strings that are not available for C-style character arrays.

    - Input
        - In C++, you can input a string from the user using the standard input stream object (std::cin) and the  getline() function from the string library.

        -  Syntax

            string myString;
            getline(cin, myString);

            OR

            // FOR C STYLED STRINGS
            char name[20];
            cin.getline(name, 20);


            - The getline reads the input stream of chatracters including white spaces.
            - The function stops reading when it encounters a newline character or the end-of-file character.

        -  If you want to input a single word without any whitespace characters, you can use the standard input stream operator (>>)

        - cin is object of istream class, getline is member funciton of istream class

        -  it is generally safer to use the "string" class to work with strings, as it provides a safer and more flexible way to manipulate strings, without worrying about buffer overflows or memory management.

    - strlen() vs size()

        Both strlen() and size() are used to find the length of a string, but they work in different ways depending on the type of string you are working with.

        strlen() is used for C-style strings, which are basically arrays of characters. To use strlen(), you pass it a pointer to the beginning of the string (the first character) and it will count how many characters there are in the string until it reaches a null character (which signals the end of the string). strlen() returns the number of characters in the string, not including the null character.

        On the other hand, size() is a method of the std::string class in C++. std::string is a modern way to work with strings in C++, and it's often easier and safer to use than C-style strings. To use size(), you call it on a std::string object, and it will return the number of characters in the string (not including the null character).

    - strcat() -> It is a function in C++ that is used to concatenate two C-style strings (character arrays) together.

        - Note that strcat() does not perform any bounds checking, so it is important to ensure that the destination array has enough space to hold both the original string and the appended string. If the destination array is not large enough, strcat() may cause a buffer overflow, which can lead to undefined behavior and security vulnerabilities.

        // This is allowed
        char s1[10] = "a";
        char s2[10] = "b";

        strcat(s1, s2);
        cout<<s1;

        // This will give error
        char s1[1] = "a"; // not enough space available to accomodate s2 in s1.
        char s2[10] = "b";

        strcat(s1, s2);
        cout<<s1;

    - compare strings

        - strcmp() -> this is used to comapre the character arrays
        - s1.compare(s2) -> this is used to compare string objects

    - Reverse a string

        - strrev() -> to reverse the c styled character array

    - cin.ignore()

        - cin.ignore() is a C++ standard library function that is used to ignore one or more characters in the input stream

        - example

            int a;
            string s;
            float b;
            
            cin>>a;            
            getline(cin, s);
            cin>>b;

            - In the above code, the getline function does not work with new line character(enter), When we input the value of a and press enter, then the number is stored in a and the new line character(enter) is still in the input buffer stream, this new line character(enter) is read by the getline function and as it encounters the new line character(enter), it stops. Because of this , input for s and b cannot be taken

            - To solve this we are using cin.ignore() to ignore the new line character(enter) in the input buffer so that the getline function can read the remaining string.

                int a;
                string s;
                float b;
                
                cin>>a;         
                cin.ignore();   
                getline(cin, s);
                cin>>b;

    - copy a string -> strcpy() function

        struct student{
            char name[20]
        }

        student s1

        strcpy(s1.name, "Amit");

## Structure

    - a structure is a user defined type

    - struct student {
            int roll;
            char name[10];
            float per;
    }

    - Pointer to the structure

        - student s1;
        - student *p;
        - p = &s1;

        - we can access the structure s1 through p by the following ways
        - (*p).roll
        - OR
        - p->roll


    - Refrence to a strucure
        - student s1;
        - student &r = s1;

        - s1.roll = 100;
        - r.roll = 101;

    - The size of a structure is the sum of its individual data members

        struct Person {
            int age;
            char name[20];
            float height;
        };

        - Assuming an int is 4 bytes, a float is 4 bytes, and each character in the array takes 1 byte, the size of the Person structure would be 28 bytes (4 bytes for age, 20 bytes for name, and 4 bytes for height).

    - Self refrencial structure

        struct data{

            int a;
            float b;
            data *p;
        }

        - data d1, d2;
        - d1.p = &d2;
        - d2.p = &d1;

        - d1.p -> a = 10; // value of a in d2 is changed.
