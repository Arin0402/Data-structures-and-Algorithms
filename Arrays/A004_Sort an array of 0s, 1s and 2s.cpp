#include <bits/stdc++.h>
using namespace std;

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