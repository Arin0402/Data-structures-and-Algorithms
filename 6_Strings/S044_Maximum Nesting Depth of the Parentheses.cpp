#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1

// 1
// using stack

// we have to count the maximum value of nested parenthesis which may or may not be continuous
class Solution {
  public:
    int maxDepth(string s) {
        
        // stack to store '('    
        stack<char> st;
        
        // max value
        int maxi = 0;
        
        int n = s.size();
        
        // iterator
        int i = 0;
        
        while(i < n){
            
            // push into stack
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')'){
                
                int count = 0;
                
                // stack has some number of '(' 
                if(!st.empty()) {
                    count = st.size(); // update count
                    st.pop(); // remove one '(' for a ')'
                }
                
                // update maxi
                maxi = max(count, maxi);
            }
            
            i++;
        }
        
        return maxi;
        
    }
};

// 2
// In the above approach, we are only calculating the size of stack i.e counting the number of '('
// so this can also be done by a count variable
class Solution {

    public:
    int maxDepth(string s) {

            int n = s.length();
            int ans=0, c=0;

            for(int i=0;i<n;i++){

                if(s[i]=='(') c++;

                else if(s[i]==')') c--;

                ans = max(ans,c);
            }
            return ans;
    }
};