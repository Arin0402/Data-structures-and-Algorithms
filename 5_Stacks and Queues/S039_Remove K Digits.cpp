#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/remove-k-digits/1

// 1
// O(N)
class Solution {
  public:
    
    string removeKdigits(string S, int k) {
        
        // answer string
        string ans = "";
        
        for(auto c : S){
        
            // elements should be in ascending order
            // previous element is greater than the current element.
            while(ans.length() > 0 && k > 0 && ans.back() > c){
                
                // decrement counter
                k--;
                
                // remove it
                ans.pop_back();
            }
            
            // push 0 only when the length of ans is not zero
            // we do not want leading zeros in the answer
            if(ans.length() || c != '0') ans.push_back(c);
        }
        
        // remove the remaining k elements
        while(ans.length() && k > 0){
            ans.pop_back();
            k--;
        }
        
        // if the ans is empty, return 0
        return ans.length() == 0 ? "0" : ans;
    }


};