#include <bits/stdc++.h>
using namespace std;

// O(n) -> total time complexity (for reason refer notes)

// heapify for max heap.

// O(logn)
void heapify(int arr[], int N, int i)
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
void buildHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;
      
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i);
    }
}