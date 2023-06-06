#include <bits/stdc++.h>
using namespace std;

// O(n*2)
// O(n)

// https://youtu.be/IFfYfonAFGc?t=615

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n , 1);
        
        // storing the previous index to backtrack in order to form LIS
        vector<int> hash(n);
        
        // finding the LIS
        for(int i = 0 ; i < n; i++){
            
            for(int j = 0; j < i ; j++){
                
                if(a[j] < a[i] && dp[i] < 1 + dp[j] ){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
                
            }
        }
        
        // printing the LIS
        
        
        // finding the index at which length is maximum
        int index;
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++ ){
            
            if(dp[i] > maxi){
                maxi = dp[i];
                index = i;
            }
        }
        
        // to store the LIS
        vector<int> ans;
        
        while(index != hash[index]){
            
            ans.push_back(a[index]);
            index = hash[index];
        }
        
        // to store the starting index
        // as for the starting index, the index is equal to hash[index]
        ans.push_back(a[index]);
        
        
        // reverse the answer to get LIS in increasing order
        reverse(ans.begin(), ans.end());
        
        for(auto itr : ans) cout<<itr<<" ";
        
        return 0;
        
    }
};