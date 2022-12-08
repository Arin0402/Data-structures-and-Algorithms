#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void reverseArray(int arr[], int left, int right)
{
    if (left > right)
        return;

    swap(&arr[left], &arr[right]);
    reverseArray(arr, left + 1, right - 1);
}

bool PalindromeOrNot(string s, int left, int right)
{

    if (left > right) // if indexes cross each other then palindrome;
        return true;

    if (s[left] != s[right]) // Or s[left] != s[s.size() - left - 1];
        return false;

    return PalindromeOrNot(s, left + 1, right - 1);
}

int main()
{
    // reverse array

    // int arr[] = {1, 2, 3, 4, 5};
    // reverseArray(arr, 0, 4);
    // print(arr, 5);

    // palindrome or not

    cout << PalindromeOrNot("MADAM", 0, 4);
}