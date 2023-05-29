#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-the-number-of-sub-arrays-having-even-sum1533/1

class Solution{   
public:
    long long countEvenSum(int arr[], int n) {
        
        long long oddCount = 0;
        
        // for empty subarray
        long long evenCount =  1;
        long long ans = 0;

        long int pref = 0;

        for(int i = 0; i < n; i++){
            
            pref += arr[i];
            
            // pref is even
            if(pref%2 == 0) ans = (ans + evenCount);
            // pref is odd
            else ans = (ans + oddCount);

            if(pref%2 == 0) evenCount++;
            else oddCount++;
        }

        return ans;
    }
};