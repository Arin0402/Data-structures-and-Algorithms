#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// 1. l = 0, ptr = 0, r = n-1
// 2. if a[ptr] == 0
//          swap a[l] and a[ptr] 
//          l++ and ptr++
//    else if a[ptr] == 1   
//          do nothing
//          ptr++
//     else
//          swap a[ptr] and a[r] 
//          r--
// 


class Solution
{
    public:
    
    void swap(int *a, int *b){
        
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sort012(int arr[], int n)
    {
        
        int l = 0; // left pointer
        int r = n -1; // right pointer.
            
        int ptr = 0;
        
        while(ptr <= r){ // elements to the right will be 2.
            
            int val = arr[ptr];
            
            if(val == 0){
                swap(&arr[ptr], &arr[l]);
                ptr++;
                l++;
            }
            else if(val == 2){ // do not increase the pointer here, as we may get 0 after swapping.
                swap(&arr[ptr], &arr[r]);
                r--;
            }
            else ptr++; // val == 1
        }
        
    }
    
};