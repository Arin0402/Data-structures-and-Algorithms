#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1
// same as previous. Only one condition is added

// 1
// using binary search
// O(logn)
class Solution {
  public:
    bool Search(int N, vector<int>& arr, int key) {
        
        int low = 0;
        int high = N -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(arr[mid] == key) return true;
            
            // for ex- 3 3 0 3 3 3 3 . key = 3
            if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
            }
            // left part is sorted
            else if(arr[low] <= arr[mid]){
                
                // lies in the range
                if(key >= arr[low] && key <= arr[mid]) high = mid-1;
                else low = mid + 1;
                
            }
            
            // right part is sorted
            else{
                
                // lies in the range
                if(key >= arr[mid] && key <= arr[high]) low = mid + 1;
                else high = mid-1;
                    
            }
            
        }
        
        return false;
    }
};
