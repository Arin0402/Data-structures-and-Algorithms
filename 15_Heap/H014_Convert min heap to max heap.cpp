#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1?page=1&sortBy=newest&query=page1sortBynewest

// just simply apply the build heap function to build the max heap.
// O(n)
class Solution{
public:

    void heapify(vector<int> &arr, int N, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
      
        // If left child is larger than root
        if (l < N && arr[l] > arr[largest])
            largest = l;
      
        // If right child is larger than largest so far
        if (r < N && arr[r] > arr[largest])
            largest = r;
      
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
      
            // Recursively heapify the affected sub-tree
            heapify(arr, N, largest);
        }
    }
    
    // Function to build a Max-Heap from the given array
    void buildHeap(vector<int> &arr, int N)
    {
        // Index of last non-leaf node
        int startIdx = (N / 2) - 1;
          
        for (int i = startIdx; i >= 0; i--) {
            heapify(arr, N, i);
        }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int N){
        
        buildHeap(arr, N);
    }
    
};
