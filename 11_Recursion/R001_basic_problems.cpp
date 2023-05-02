#include <iostream>
using namespace std;

void print_1_to_N(int i, int n)
{
    if (i > n) // base case
        return;

    cout << i << endl;

    print_1_to_N(i + 1, n); // recursive call;
}

void print_1_to_N_backtrack(int i, int n)
{ // print from 1 to n using backtracking. Use of i+1 not allowed . We Will use i-1;

    if (i == 0)
        return;

    print_1_to_N_backtrack(i - 1, n); // recursive call is being made before printing it;

    cout << i << endl;
}

void print_N_to_1_backtrack(int i, int n)
{

    if (i > n)
        return;

    print_N_to_1_backtrack(i + 1, n);

    cout << i << endl;
}

int main()
{
    // print_1_to_N(1, 5); // print from 1 to n;

    // print_1_to_N_backtrack(5, 5); // print from 1 to n using backtracking;

    print_N_to_1_backtrack(1, 5); // print from 1 to n using backtracking;
}