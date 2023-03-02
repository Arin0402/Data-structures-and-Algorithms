#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// 1
// O(n+m)
// O(n+m)
class Solution
{
public:
    // O(n+m)
    void heapify(vector<int> &arr, int n, int ind)
    {

        int largest = ind;

        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != ind)
        {
            swap(arr[largest], arr[ind]);
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        // push all the elements of both the arrays then call heapify function.
        vector<int> arr;

        for (int i = 0; i < n; i++)
            arr.push_back(a[i]);
        for (int i = 0; i < m; i++)
            arr.push_back(b[i]);

        for (int i = (n + m) / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n + m, i);
        }

        return arr;
    }
};
