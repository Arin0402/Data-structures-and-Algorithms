#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

// 1
// O(N)
// O(N)
class Solution {
  public:
  
    // avoid pushing operands into the stack.
    int checkRedundancy(string s) {
        
        int n = s.size();
        stack<char> st;
        
        for(int i =0; i < n; i++){
            
            if(st.empty()){
                if(s[i] == '(') st.push(s[i]);
            }
            else if(s[i] == ')'){
                
                // number of operators between opening and closing bracket.
                int len = 0;
                
                while(!st.empty() && st.top() != '('){
                    st.pop();
                    len++;
                }
                
                // if no operator, then there is redundancy.
                if(len == 0 ) return 1;
                st.pop();
                
            }
            else if(s[i] == '(') st.push(s[i]);
            // only push if it is an operator.
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') st.push(s[i]);
            
        }
        
        return 0;
    }
};
