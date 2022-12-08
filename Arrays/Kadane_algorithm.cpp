// This algorithm is used to find the maximum contiguous subarray sum
#include <iostream>
#include <climits>
using namespace std;
int maxSubArraySum(int arr[], int n)
{
    int max_sum = INT_MIN;
    int max_sum_so_far = 0;

    for (int i = 0; i < n; i++)
    {
        max_sum_so_far = max_sum_so_far + arr[i];
        if (max_sum < max_sum_so_far)
            max_sum = max_sum_so_far;
        if (max_sum_so_far < 0)
            max_sum_so_far = 0;
        }

    return max_sum;
}
int main()
{
    int a[] = {-2, -3, -1, -2};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}