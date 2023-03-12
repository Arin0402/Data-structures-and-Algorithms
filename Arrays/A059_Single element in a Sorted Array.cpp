#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1

// 1
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int low = 0;
        int high = n-1;
        
        // only one element
        if(n == 1) return arr[0];
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            // mid as starting
            if(mid == 0 && arr[mid] != arr[mid + 1]) return arr[mid];
            
            // mid as last
            if(mid == n-1 && arr[mid] != arr[mid -1]) return arr[mid];
            
            // base condition check
            if(mid -1 >= 0 && mid + 1< n && arr[mid] != arr[mid-1] && arr[mid] != arr[mid + 1] )
                return arr[mid];
            
            // mid is even
            if(mid%2 == 0){
                if(arr[mid] != arr[mid+1]) high = mid-1;
                else low = mid + 1;
            }
            else{
                if(arr[mid] != arr[mid + 1]) low = mid+ 1;
                else high = mid-1;
            }
            
        }
        
        return -1;
        
    }
};