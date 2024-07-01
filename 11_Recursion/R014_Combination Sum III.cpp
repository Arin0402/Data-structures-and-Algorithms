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
  
    vector<vector<int>> ans;
    vector<int> temp;
    
    void helper(int start, int sum, int K, int N){
 
        if(K == 0){
            if(sum == N) ans.push_back(temp);
            return;
        }
        
        
        for(int i = start; i <= 9; i++){
            
            temp.push_back(i);
            helper(i + 1, sum + i, K - 1 , N);
            temp.pop_back();
        }
                
    }
    
  
    vector<vector<int>> combinationSum(int K, int N) {
    
        helper(1, 0, K, N);
        return ans;
    }
};
