#include <bits/stdc++.h>
using namespace std;

// Solution 1;
// Sort the array
// O(NlogN)

// Solution 2
// store all the elements in set.
// set store elements in ascending order.
// O(NlogN)

// Solution 3
// Min Heap
// insert all the elements in min heap
// extract the top elements K times
// O(N + klogN)

// Solution 4
// Max Heap
// insert all the elements in max heap
// extract the top elements N - K times
// O(N + (N - k) logN)

// Solution 5
// IMPORTANT
// Using quick select.
// Run quick sort algorithm on the input array
// In this algorithm pick a pivot element and move it to it’s correct position
// Now, if index of pivot is equal to K then return the value, else if the index of pivot is greater than K, then recur for the left subarray, else recur for the right subarray
// Repeat this process until the element at index K is not found
// O(N^2) in worst case and O(N) on average

// Solution 6
// Priority queue (max)
// by default priority queue is max heap in cpp.
// insert k elements
// O(K log K +  (N – K) log K)

// Soution using quick select
class Solution
{
public:
    
    // same partition function of quicksort.
    int partition(int low, int high, int arr[])
    {

        int pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element and indicates
                               // the right position of pivot found so far

        for (int j = low; j < high; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {

        if (l <= r)
        { // why equal ? case in which single element is there.

            int pi = partition(l, r, arr);

            if (pi == k - 1)
                return arr[pi]; // partition is equal to the required position.

            else if (pi > k - 1)
            { // go left;

                kthSmallest(arr, l, pi - 1, k);
            }
            else
            { // go right.

                kthSmallest(arr, pi + 1, r, k);
            }
        }
    }
};