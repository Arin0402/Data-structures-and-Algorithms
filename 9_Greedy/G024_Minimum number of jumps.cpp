#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// https://www.youtube.com/watch?v=7SBVnw7GSTk

// 1
// dp
// O(N^2)

// 2
// O(n)
// O(1)
class Solution{
  public:
    int minJumps(int arr[], int n){
        
        // indexes of the range
        int l = 0;
        int r = 0;
        
        int jumps = 0;
        
        while( r < n-1){
            
            // farthest index that can be reached in that range
            int farthest = 0;
            
            for(int i = l; i <= r; i++){
                farthest = max(farthest, arr[i] + i);
            }
            
            // move the left index
            l = r + 1;
            
            // update r only if the range can be moved further, otherwise if range can not be moved further, then it is not possible
            if(farthest > r)
                r = farthest;
            else return -1;
            
            jumps++;
     
        }
        
        return jumps;
        
    }
};
