#include <bits/stdc++.h>
using namespace std;

// 1
// try all sub arrays.
// O(n^2)
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        
        // initialise minimum length with n + 1;
        int min_len = n +1;
        
        for(int i = 0; i < n; i++){
            
            int sum = arr[i]; // add the initital element of that subarray.
            
            if(sum > x) return 1; // maybe first elememnt is greater so return 1.
            
            for(int j = i +1  ; j < n; j++ ){
                
                sum += arr[j]; // add element.
                
                // check.
                if(sum > x){
                    min_len = min(min_len , j - i + 1);
                    break;
                }
                
            }
        }
        
        // not found.
        if(min_len == n + 1) return 0;
        
        return min_len;
        
    }
};

// 2
// two pointer technique.
// valid for only positive numbers in the array.

class Solution1{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int minLen = n + 1; 
        
        // left and right pointer.
        int start = 0, end = 0;
        
        int sum  =0;
        
        while(end < n){
            
            // add element untill the sum is less than or equal to x.
            while(sum <= x && end < n){
                sum += arr[end];
                end++;
            }
            
            // sum is greater than x.
            while(sum > x && start < n ){
                
                // check for minimum length in all lengths starting from start index.
                minLen = min(minLen , end - start  );
                
                // decrese the sum.
                sum -= arr[start++];
            }
        }
        
        // not found.
        if(minLen == n+1) return 0;
        
        return minLen;
    }
};