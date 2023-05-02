#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/outermost-parentheses/1

class Solution {
  public:
    string removeOuter(string& s) {
        
        // stack to store the elements
        stack<char> st;
        
        int n = s.size();
        
        // pointers        
        int left = 0;
        int right = 0;
        
        string ans = "";
        
        while(right < n){
            
            if(s[right] == '('){
                st.push('(');
            }
            else st.pop();
            
            // got a primitive string.
            if(st.empty()){
                
                // escape the ( of primitive string
                left++;
                
                // escape the ) of primitive string
                int prev = right - 1;
                
                // add it to the answer
                ans += s.substr(left, prev - left + 1);
                
                // go to next.
                right++;
                left = right;
            }
            else 
                // go to next
                right++;
        }
        
        
        return ans;
    }
};