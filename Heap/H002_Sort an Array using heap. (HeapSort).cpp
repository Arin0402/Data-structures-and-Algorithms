#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/heap-sort/1

// The time complexity of heap sort is O(n logn) in all three cases (best case, average case, and worst case).
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        
        int largest = i;
        
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        
        int size = n;
        for(int i = n-1; i>0;i--){
            
            swap(arr[0],arr[i]); //move current root to end
            heapify(arr,i,0);
        }
        
    }
};

