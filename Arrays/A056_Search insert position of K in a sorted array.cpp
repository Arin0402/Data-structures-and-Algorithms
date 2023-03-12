#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1

// 1
// using binary seacrh

class Solution{
    public:
    int searchInsertK(vector<int> v, int n, int x)
    {
        int low = 0;
        int high = n-1;
        
        int ind = -1;
        
        // x is less than the first element.
        if(x < v[0]) return 0;
        
        // x is greater than the last element.
        if(x > v[n-1]) return n;
        
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(v[mid] == x){
                return mid;
            } 
            else if(v[mid] > x) high = mid-1;
            else{
                
                ind = mid;
                low = mid + 1 ;
                
            }
        }
        
        
        return ind+1;
    }
};