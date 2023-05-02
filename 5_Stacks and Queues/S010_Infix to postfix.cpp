#include <bits/stdc++.h>
using namespace std;

// Anuj bhaiya 
// https://www.youtube.com/watch?v=_PU5t-gk_B4
// https://www.youtube.com/watch?v=m7SGekhd1mQ

// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

class Solution {
  public:
    
    int prec(char c){
        
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if(c == '+' || c == '-') return 1;
        else return -1;
        
    }
  
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        
        stack<char> st;
        
        string postfix = "";
        
        for(auto c : s){
            
            // open bracket
            if(c == '(') st.push('(');
            
            // operand
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                postfix += c;
            }
            
            // close bracket
            else if(c == ')'){
                
                while(st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            
            // operator
            else{
                
                while(!st.empty() && prec(c) <= prec(st.top())){
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
        
    }
};

