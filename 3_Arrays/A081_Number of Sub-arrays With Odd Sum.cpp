#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
// https://www.youtube.com/watch?v=svvIB5pPc2E

#define MOD 1000000007

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();
        int oddCount = 0;
        // for empty subarray
        int evenCount = 1;

        int ans = 0;

        long int pref = 0;

        for(int i = 0; i < n; i++){
            
            pref += arr[i];
            
            // - pref is even
            // - if we remove the subarray with odd sum from the current subarray, then the remaining subarray will have the 
            // sum as odd. (current prefix sum is even)
            // - so if we can find out the count of subarrays having odd sum, we can remove them from the current subarray to 
            // get the sum as odd
            // - so the the total number of subarray whose count is odd is will be added to the answer
            if(pref%2 == 0) ans = (ans + oddCount)%MOD;
            
            // pref is odd
            else ans = (ans + evenCount)%MOD;

            if(pref%2 == 0) evenCount++;
            else oddCount++;
        }

        return ans;
    }
};