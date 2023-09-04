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
            
            int good = 0; // <= k // this is the size of window
            int bad = 0; // > k
            
            // count elements <= k
            for (int i =0 ; i < n ; i++){
                if(arr[i] <= k) good++;
            }
            
            // for Ist window.
            for(int i = 0; i< good; i++){
                
                if(arr[i] > k) bad++;
            }
            
            int ans = bad;
            
            // sliding window.
            for (int i =1; i < n - good + 1; i++){
                
                if(arr[i - 1] > k ) bad--;
                if(arr[i + good - 1] > k) bad++;
                
                ans = min(ans, bad);
            }
            
            return ans;
        }
};

