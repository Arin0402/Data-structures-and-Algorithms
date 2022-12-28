#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1?page=1&sortBy=accuracy

// 1
// memo
// O(n*n)  extra n for FOR LOOP
// O(n) + O(n)
class Solution{
    public:
    int helper(int i, int n, int k, vector<int> &arr, vector<int> &dp){
        
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int sum = -1e9;
        int maxEle = -1;
        
        for(int j = i; j < min(n, i + k) ; j++){
            
            maxEle = max(maxEle, arr[j]);
            int val = (j - i + 1)*maxEle + helper(j + 1, n, k, arr, dp);
            
            sum = max(sum, val);
        }
        
        return dp[i] = sum;
        
    }
    int solve(int n, int k, vector<int>& arr){
        
        vector<int> dp(n, -1);
        return helper(0, n, k, arr, dp);
    }
};

// 2
// tab
// O(n*n)  extra n for FOR LOOP
// O(n)
class Solution{
    public:
    
    int solve(int n, int k, vector<int>& arr){
        
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--){
            
            int sum = -1e9;
            int maxEle = -1;
            
            for(int j = i; j < min(n, i + k) ; j++){
                
                maxEle = max(maxEle, arr[j]);
                int val = (j - i + 1)*maxEle + dp[j + 1];
                
                sum = max(sum, val);
            }
            
            dp[i] = sum;
        }
        
        
        return dp[0];
    }
};


