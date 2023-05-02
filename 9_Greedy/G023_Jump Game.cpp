#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/jump-game/1

// 1
// try recursion
// TC - exponential 

// 2
// greedy 

// we will iterate in the backward direction and check from which index, we can reach the 
// lastreach index ( for the first case, lastreach is the last index of the array)
// if we can reach the last reach index, then we will update the lastreach to curr.
class Solution {
  public:
    int canReach(int a[], int n) {
        
        // target index to which we have to reach.
        int lastreach = n-1;
        
        // current index
        int curr = n-2;
        
        while(curr >= 0){
            
            // can reach the target index from the current index
            // update the target index and check for this index now onwards
            if(lastreach - curr <= a[curr]) lastreach = curr;
            
            
            // decrement
            curr--;
            
        }
        
        // we can reach the first index i.e we can reach the last index
        if(lastreach == 0) return true;
        
        // not possible
        return false;
    }
};