#include <bits/stdc++.h>
using namespace std;

// Solution video of geeks for geeks editorial.

class Solution{
  public:
    int minJumps(int arr[], int n){
        
        if(n == 1) return 0; // only one element
        if(arr[0] == 0) return -1; // can not move forward.
        
        int maxReach = arr[0]; // maximum index to which we can reach.
        int steps = arr[0]; // steps can be taken in a jump.
        
        int jumps = 1; // initial jump.
        
        for(int i = 1 ; i < n; i++ ){
            
            if(i == n-1) return jumps; // reached the end, return jumps.
            
            maxReach = max(maxReach, i + arr[i]); // update the maxReach 
            steps--; // decrease the step.
            
            if(steps == 0){ // steps for a jump are over, we have to jump now.
                
                if(i == maxReach) return -1; // can not move further, as maxReach is same as i.
                
                steps = maxReach - i; // steps wiil be increased to maxreach minus the current index. 
                jumps++; // increase jump.
            }
            
        }
        
        return -1;
        
    }
};
