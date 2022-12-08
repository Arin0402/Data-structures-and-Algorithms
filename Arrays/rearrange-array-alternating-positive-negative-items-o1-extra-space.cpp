// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
//  contributed by me
#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = *a;
}
void rotate(int arr[], int l, int r)
{
    int t = arr[r];
    for (int i = r; i > l; i--)
    {
        swap(&arr[i], &arr[i - 1]);
    }
    arr[l] = t;
}

void rearrange(int arr[], int n)
{
    if (n == 1)
        return;

    int l = 0, r = 1;

    while (l < n && r < n)
    {
        cout << l << " " << r << endl;
        if (l % 2 == 0)
        {

            if (l < r)
            {
                if (arr[l] < 0)
                {
                    l++;
                    r++;
                }
                else if (arr[l] >= 0 && arr[r] < 0)
                {
                    rotate(arr, l, r);
                    l++;
                }
                else
                    r++;
            }
            else
                r++;
        }
        else
        {
            if (l < r)
            {
                if (arr[l] >= 0)
                {
                    l++;
                    r++;
                }
                else if (arr[l] < 0 && arr[r] >= 0)
                {
                    rotate(arr, l, r);
                    l++;
                    // r++;
                }
                else
                    r++;
            }
            else
                r++;
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{

    int arr[] = {2, 3, 5, 56, -423, -35, -34, 23};
    // int arr[] = {0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}