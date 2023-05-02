#include <iostream>
using namespace std;

// function to calculate sum of numbers upto n;

// Parameterised function

int R_Sum(int n, int count) // R means type is return;
{

    if (n < 0)
        return count;

    count += n;

    // -----This---------

    // count = R_Sum(n - 1, count);
    // return count;

    // ---------OR--------
    return R_Sum(n - 1, count);
}

// ----------OR----------------

void V_Sum(int n, int count) // V means type is void;
{

    if (n < 0)
    {
        cout << count << endl;
        return;
    }

    count += n;
    V_Sum(n - 1, count);
}

// Functional Recursion

int R_Sum_F(int n)
{ // F means type is Functional;

    if (n <= 0)
        return 0;

    return n + R_Sum_F(n - 1);
}

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    // Parameterised functions

    cout << R_Sum(4, 0) << endl; // function returning count;
    // V_Sum(3, 0); // functoin printing count;

    // Functional functions

    // cout << R_Sum_F(3) << endl;
    // cout << factorial(5) << endl; // factorial of a number;
}