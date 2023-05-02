#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/koko-eating-bananas/1

// 1
// usnig n=binary search

class Solution {
  public:
    
    // to check if the mid value will fulfill the condition or not
    bool isSufficient(vector<int>& piles, long long int mid, int H){
        
        long long int cnt = 0;
        
        for(auto pile : piles){
            cnt += pile/mid;
            
            // check for extra hour for a particular pile
            if(pile%mid != 0) cnt++;
            
        }
        
        // number of hours required are <= given hours        
        return (cnt <= H);
    }
  
    int Solve(int N, vector<int>& piles, int H) {
     
        // max value of piles
        int maxi = INT_MIN;
        
        for(int i = 0; i < N; i++){
            maxi = max(maxi, piles[i]);
        }
        
        // minimum banana can be one.
        int low = 1;
        
        // maximum banana can be upto the maximum value
        int high = maxi;
        int ans = -1;
        
        while(low <= high){
            
            long long int mid = low + (high - low)/2;
            
            // satisfies the condition , move left.
            if(isSufficient(piles, mid, H)){
                ans = mid;
                high = mid -1;
            }
            else low = mid + 1;
            
        }
        
        return ans;
        
        
    }
};