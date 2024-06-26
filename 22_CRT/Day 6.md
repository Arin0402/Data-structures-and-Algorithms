## Day 6

_------------- These are the notes of linked list folder ----------------------_

    1.  This is correct

        int myvar;
        int *myptr;
        myptr = &myvar;

        OR

        int myvar;
        int *myptr = &myvar;

        this is wrong

        int myvar;
        int * myptr;
        *myptr = &myvar; // faulty line

        // The asterisk (*) in the pointer declaration (line 2) only indicates that it is a pointer, it is not the dereference operator (as in line 3).


    2.  Only addition and subtraction can be performed on pointers

    3. *p++   // same as *(p)++: dereference pointer, and increment the value it points to
        *++p   // same as *(++p): increment pointer, and dereference incremented address
        ++*p   // same as ++(*p): dereference pointer, and increment the value it points to
        (*p)++ // dereference pointer, and post-increment the value it points to

    4. num += 1 is rather equivalent to ++num.

    5.  int x;
        int y = 10;
        const int * p = &y;
        x = *p;          // ok: reading p
        *p = x;          // error: modifying p, which is const-qualified

    VOID POINTER

    6. void pointer is a pointer which has no associated data type with it.

    7. it can point to any type of data and can can be typecasted to any data type

    8.  int a = 10;
        void *ptr = &a;
        cout<<*ptr<<endl;  // this is wrong as *ptr has no data type so we have to type cast it.

        int a = 10;
        void *ptr = &a;
        cout<<*(int*)ptr<<endl;  // typecasted to int* data type.

    9. Used in malloc and calloc function to allocate memory to any type of data. These function return void pointer.
        the void returned is typecasted into desired datatype.

        like ..   struct node* =  (struct node*)malloc(sizeof(struct node*))
                                        ^---------- this is type casted

    NULL POINTER

    10.  A NULL pointer is a pointer that does not point to any memory location . It represets an invalid memory location

        Ex- int *ptr = NULL;
            cout<<ptr;  //output will be zero;

        Ex- int *ptr, *ptr1 = nullptr;
            cout << ptr << endl; // output will be some memory address;
            cout << ptr1 << endl; // output wiil be zero;

        Used in error handling
        Sometimes malloc returns null pointer;

    11. Use of single pointer variable to assign values to two different variables

        int a, b;
        int *ptr;

        // assign value to a
        ptr = &a;
        *ptr = 10;

        // assign value to b
        ptr = &b;
        *ptr = 20;

        cout << a << " "<< b << endl;

        Output -> 10 20

    12. Concept of pointer in array

        int numbers[5]; // array

        int *p; // pointer

        p = numbers; // address of the first integer of array
        *p = 10; // assign value

        p++; // increment address
        *p = 20; // assign value to the second integer

        p = &numbers[2]; // address of the third integer
        *p = 30; // assign value

        // print
        for (int i = 0; i < 5; i++)
            cout << numbers[i] << " ";

        Output -> 10 20 30 0 0

    13. Pointer to a function

        // add two numbers
        int add(int a, int b) return a + b;

        void function_pointer()
        {

            // NOTE -> here use of brackets around *p are important. If we do not use it then it will consider it as
                        a function whose name is p and the return type is address of integer.
                        - It will look something like this -> int* p(int, int)
                                                                ^--------------- return type


            int (*p)(int, int); // pointer to a function
            p = add;
            int c = (*p)(2, 3);
            cout << c << endl;

            Output -> 5
        }

    14. int *p , here int * is a datatype to store the adderess of the integer.

    15. *p1 = *p2 , In assignment operator, right hand side will be solved first (i.e *p2 will be derefrenced first and then it
                will be assigned to memory address stored in p1)

    16. All types of pointers (like int* p, float* p, double *p etc) have size of memory as int as the pointer only stores the address which is of integer type. the datatype (i.e int in int* , float in float* ) is used to define that what value will be stored at the memory address stored in the pointer variable.

    17. Referencing

        int a;

        int &r = a; // r is referencing a i.e r is accessing the memory address of a

        a = 10

        cout<<a -> 10

        r = 20

        cout<<a -> 20


        - We have to always initialise the reference variable
        - reference to the variable cannot be changed if it is still in the memory

        - Advantages -- simple syntax
                    -- takes less memory

        - Disadvantage -- we cannot create reference of the address so that's why we cannot create refrence of array

                            int a[10];

                            int &r = a // This is wrong
                            int &r = a[0] // This is correct

    18. Dynamic array

        -  int * arr = new int[length];

        - Dynamic array is created at runtime so the compiler cannot delete the memory allocated to the array, so we have
            to explicilty delete the memory else it will remain allocation till the life of the program.

        - Syntax - delete[] arr

        - Note: If only a single element is declared on the heap, then the delete operator is used instead (without the square brackets []).

    19.  stack memory is used for storing temporary data with a limited lifetime, and its memory is managed automatically by the system. Heap memory is used for storing data with a variable size or lifetime, and its memory must be manually allocated and deallocated by the programmer.
