#include <iostream>
using namespace std;

void note()
{

    /* 1
        this is correct

        int myvar;
        int * myptr;
        myptr = &myvar;

        this is wrong

        int myvar;
        int * myptr;
        *myptr = &myvar; // faulty line

        // The asterisk (*) in the pointer declaration (line 2) only indicates that it is a pointer, it is not the dereference operator (as in line 3).


    2.  Only addition and subtraction can be performed on pointers

    3. *p++   // same as *(p++): increment pointer, and dereference unincremented address
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

    6. void pointer is a pointer which has no associated datay type with it.

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
            cout<<ptr;  // output will be zero;

        Ex- int *ptr, *ptr1 = nullptr;
            cout << ptr << endl; // output will be some memory address;
            cout << ptr1 << endl; // output wiil be zero;

        Used in error handling
        Sometimes malloc returns null pointer;

    */
}
void type_1()
{
    // use of single pointer to assign values to two different variables which are not initialized yet
    int firstvalue, secondvalue;

    int *ptr;
    ptr = &firstvalue;
    *ptr = 10;
    ptr = &secondvalue;
    *ptr = 20;

    cout << firstvalue << endl;
    cout << secondvalue << endl;
}
void type_2()
{
    int a = 10;

    int *ptr1, *ptr2;

    ptr1 = &a;
    *ptr1 = 34;

    cout << *(ptr1) << endl;
    cout << *(ptr1 + 1);
}

void pointer_concept_in_array()
{
    int numbers[5];

    int *p;

    p = numbers;
    *p = 10;

    p++;
    *p = 20;

    p = &numbers[2]; // another & is being used
    *p = 30;

    for (int i = 0; i < 5; i++)
        cout << numbers[i] << " ";
    cout << endl;
}

int add(int a, int b)
{
    return a + b;
}

void function_pointer()
{

    int (*p)(int, int); // pointer to a function
    p = add;
    int c = p(2, 3);
    cout << c << endl;
}
int main()
{
}