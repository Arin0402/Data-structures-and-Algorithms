#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end)
{

    if (start < end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse(arr, start + 1, end - 1);
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    reverse(arr, 0, 5);
    print(arr, 6);

    return 0;
}