#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

// 1
// count the elements which are  >= k, call this n.
// for each subarray for size n, check the number of elements greater than k.
// return the minimum of all.   
// O(n^2);

// 2
// Optimised version of above. (Sliding window)
// sliding window.
// set window size equal to count of elments <= K.
// move window and check for the elements greater than > k.

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        
        int winsize = 0; // count of elements <= k
        
        for(int i = 0; i < n; i++){
            if(arr[i] <= k) winsize++;
        }
        
        // for the first window
        
        int bad = 0;
        
        for(int i = 0; i < winsize; i++){
                
            if(arr[i] > k) bad++;
            
        }
        
        int ans = bad;
        
        int l = 0; 
        int r = winsize;
        
        while(r < n){
            
            if(arr[r++] > k) bad++;
            if(arr[l++] > k) bad--;
            
            ans = min(ans, bad);
        }
        
        return ans;   
        
    }
};
