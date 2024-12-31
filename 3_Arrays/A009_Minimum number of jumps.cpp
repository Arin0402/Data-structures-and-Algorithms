#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=7SBVnw7GSTk

// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution{
  public:
    int minJumps(int arr[], int n){
        
        int l = 0;
        int r = 0;
        
        int jumps = 0;
        
        while( r < n-1){
            
            int farthest = 0;
            
            for(int i = l; i <= r; i++){
                farthest = max(farthest, arr[i] + i);
            }
                                    
            if(farthest > r){
                l = r + 1;
                r = farthest;
            }                
            else return -1;
            
            jumps++;
     
        }
        
        return jumps;
        
    }
};