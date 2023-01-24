#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        
        stack<int> st;
        
        for(auto c: S){
            
            if( c >= '0' && c <= '9' ) st.push(c - '0');
            else{
                
                int second = st.top();
                st.pop();
                
                int first = st.top();
                st.pop();
                
                if(c == '*'){
                    int res = first*second;
                    st.push(res);
                }
                else if(c == '/'){
                    int res = first/second;
                    st.push(res);
                }
                else if(c == '+'){
                    int res = first + second;
                    st.push(res);
                }
                else if(c == '-'){
                    int res = first - second;
                    st.push(res);
                }
                
            }
        }
        
        return st.top();
    }
};