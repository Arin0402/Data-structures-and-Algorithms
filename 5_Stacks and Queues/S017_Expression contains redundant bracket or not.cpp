#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

// easy
// 1
// O(N)
// O(N)
class Solution {
  public:
    int checkRedundancy(string s) {
        
        int n = s.size();
        
        stack<char> st;
    
        for(int i =0; i < n; i++ ){
            
            if(s[i] == ')'){
                
                // if directly open bracket is there and nothing in between then 
                // it is redundant    
                if(st.top() == '(') return 1;
                
                // remove the operators in between
                while(st.top() != '('){
                    st.pop();
                }
                
                // remove the open bracket
                st.pop();
                
            }
            // push only if it is a operator or open bracket.
            else if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') st.push(s[i]);
            
        }
        
        return 0;
    }
};
