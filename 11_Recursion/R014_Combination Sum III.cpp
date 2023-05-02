#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/combination-sum-iii/1

// 1
// create a array from 1 to 9
// then simple pick an not pick
// TC = 2^9

// 2
// also can be done like this

class Solution {
  public:
    
    void helper(int ind, int start, int K, int target, vector<int> &ds, vector<vector<int>> &ans){
        
        if(ind == K){
            
            if(target == 0)
                ans.push_back(ds);
            return;
        }
                
        for(int i = start; i <= 9; i++){
            
            if(i > target) break;
            
            ds.push_back(i);
            helper(ind + 1, i + 1, K, target - i, ds, ans);
            ds.pop_back();
        }
        
           
    }
    vector<vector<int>> combinationSum(int K, int N) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        helper(0,1, K , N, ds, ans);
        
        return ans;
    }
};