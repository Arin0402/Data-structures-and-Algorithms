#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/839d6ba2c2e4c669ba9d9d9f32ad20118937284e/1

// 1
// brute force 
// start from the window of size 2.
// check the condition for the first window of that size and then slide the window by one
// then continue the same procedure for the windows of size 3,4...n
// TC - O(N^2)

// 2
// can be done in O(n)
// replace the uppercase characters by -1 and lower case characters by 1
// then count the number of substrings that sum to zero
// this can be done using map
class Solution
{
    public:
    int countSubstring(string S)
    {
        
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        
        for(auto ele : S){
            
            int val;
            
            // upper case element
            if(isupper(ele)){
                val = -1;
            }
            // lower case element
            else val = 1;
            
            sum += val;
            
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            
            mp[sum]++;
        }
        
        return ans;
    }
};