#include <bits/stdc++.h>
using namespace std;

// 1
// using extra space

// 2
// reverse algorithm

class Solution{
	public:

    void Reverse(int arr[], int start, int end)
    {
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    }
    // Function to Rotate k elements to right
    void Rotateeletoright(int arr[], int n, int k)
    {
        // Reverse first n-k elements
        Reverse(arr, 0, n - k - 1);
        // Reverse last k elements
        Reverse(arr, n - k, n - 1);
        // Reverse whole array
        Reverse(arr, 0, n - 1);
    }

};
