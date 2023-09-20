#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

// 1
// extra space , convert into array and then find kth element.

// 2
// use priority queue.
// Klogk + (N - k)logk

// 3
// using binary search
// Similar to find median in matrix question.
// get the number of elements smaller than the target
int countElements(int arr[], int low, int high, int target)
{

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int kthSmallest(int mat[1000][1000], int n, int k)
{

    // range
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {

            cnt += countElements(mat[i], 0, n - 1, mid);
        }

        if (cnt <= k - 1)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
