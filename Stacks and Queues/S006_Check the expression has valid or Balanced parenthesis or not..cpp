#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            if(st.empty()) st.push(s[i]);
            else if(s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
            else {
                
                if(s[i] == ']' && st.top() != '[') return false;
                if(s[i] == '}' && st.top() != '{') return false;
                if(s[i] == ')' && st.top() != '(') return false;
                
                st.pop();
            }
        }
        
        if(st.empty()) return true;
        return false;
        
    }

};