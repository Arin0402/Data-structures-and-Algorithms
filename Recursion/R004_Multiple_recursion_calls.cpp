#include <iostream>
using namespace std;

int fibonacci(int n)
{

    if (n <= 1)
    {
        return n;
    }

    // int first = fibonacci(n - 1);
    // int second = fibonacci(n - 2);
    // return first + second;

    // ----------OR--------------

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{

    cout << fibonacci(4) << endl;
}