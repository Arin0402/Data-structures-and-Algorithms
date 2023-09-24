#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/valid-substring0624/1
// https://www.youtube.com/watch?v=VdQuwtEd10M

// 1
// O(N^3)
// O(N)
// find all the substrings and find the largest one.

// 2
// O(N)
// O(N)
class Solution {
  public:
    int findMaxLen(string s) {
        
        int n = s.size();
        
        stack<int> st;
        st.push(-1);
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            
            if(s[i] == '(') st.push(i);
            else{
                
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxi = max(maxi,  i - st.top());
                }
            }
        }
        
        
        return maxi;
    }
};

// 3
// O(N)
// O(1)

class Solution {
  public:
    int findMaxLen(string s) {
        
        int n = s.size();
        int maxi = 0;
        
        // number of open bracket.
        int open = 0;
        
        // number of close bracket.
        int close = 0;
        
        for(int i = 0; i < n; i++){
            
            if(s[i] == '(') open++;
            else close++;
            
            // both are equal.
            if(open == close) maxi = max(maxi, 2*open);
            
            // close becomes more so reset.
            if(close > open) open = close = 0;
        }
        
        open = close = 0;
        
        for(int i = n-1; i >= 0; i--){
            
            if(s[i] == '(') open++;
            else close++;
            
            // both are equal.
            if(open == close) maxi = max(maxi, 2*open);
            
            // open becomes more so reset.
            if(open > close) open = close = 0;
        }
        
        
        return maxi;
    }
};