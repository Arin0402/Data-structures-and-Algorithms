#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/description/

// 1
// O(n^2)
// find for each index.

// 2
// O(n)

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();

        // creating prefix array.
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = arr[i] + prefix[i-1];
        }
        
        // map to store the occurence of prefix sums
        unordered_map<int, int> mp;
        int count = 0;

        for(int i = 0; i < n; i++){
            
            // value if k is not added.
            int val = prefix[i] - k;
            
            // directly increase the count.
            if(prefix[i] == k) count++;

            if(mp.find(val) != mp.end()){
                count += mp[val];                
            }            

            // first time occuring.
            if(mp.find(prefix[i]) == mp.end()) mp[prefix[i]] = 1;
            // occured before so increase the value.
            else mp[prefix[i]]++;
        }

        return count;

    }
};