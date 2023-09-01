#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    // swap function
    void swap(int* a,int* b){
        int t= *a;
        *a = *b;
        *b = t;        
    }
    
    // reverse function
    void reverse( vector<int> &arr, int start){
        int end = arr.size() -1 ;
        
        while(start < end ){
            swap(&arr[start] , &arr[end]);
            start++;
            end--;
        }
    }

    
    void nextPermutation(vector<int>& arr) {
        
        int n = arr.size();
        int breakpoint = -1;        
        
        for(int i = n-1; i > 0 ; i--){
            
            if(arr[i-1] < arr[i] ) {
                    
                // fisrt element from back which is greater than it's succeding element.
                breakpoint = i-1; 
                break;
            }
        }
        
        if(breakpoint >= 0){
            
            
            // replace the breakpoint element with the first largest element from the back.
            for(int i = n-1; i > 0 ; i--){
                
                if(arr[i] > arr[breakpoint]) {      
                    
                    swap(&arr[breakpoint], &arr[i]);
                    break;
                }
            }
            
        }
        
        // after swapping , all the elements after breakpoint will be in decreasing order.
        // so reverse them to get the smallest order.
        reverse(arr, breakpoint +1 );
        
    }
};