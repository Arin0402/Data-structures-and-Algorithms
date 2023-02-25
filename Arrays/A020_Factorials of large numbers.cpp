#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// dry run with example to understand.
// O(N^2).

class Solution {
public:

    void multiply(vector<int> &ans, int n ){
        
        int carry = 0;
        
        for(int i = 0 ; i < ans.size() ; i++){
            
            int mul = ans[i]*n  + carry;
            
            ans[i] = mul%10;
            carry = mul/10;
            
        }
        
        while(carry){
            
            ans.push_back( carry%10);
            
            carry /= 10;
        }
        
        
    }
    
    vector<int> factorial(int N){
        
        vector<int> ans;
        
        ans.push_back(1);
        
        for(int i = 2; i <= N; i++ ){
            
            multiply(ans, i);
            
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
    }
};