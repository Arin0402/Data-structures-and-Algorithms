#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parenthesis-string/description/

// 1
// O(N)

class Solution {

    public:
    bool checkValidString(string s) {
        
        // count of open brackets
        int open = 0;
        // count of stars
        int star = 0;
        // count of close brackets
        int close = 0;

        int n = s.size();

        stack<char> st;

        for(int i = 0; i < n; i++){
            
            if(s[i] == '('){
                open++;
                st.push(s[i]);
            }
            else if(s[i] == '*'){
                star++;
                st.push(s[i]);
            }
            else{
                
                // nothing abvailable to balance
                if(open == 0 && star == 0) return false;

                // to check if we have to remove the opening bracket or not from
                // the stack
                bool flag = false;

                // open bracket is available, so we would remove it
                if(open > 0){
                    flag = true;
                    open--;
                }
                else star--;

                // find the open bracket in the stack and remove it.
                if(flag){
                    
                    int countStar = 0;

                    while( st.top() != '('){
                        countStar++;
                        st.pop();
                    }
                    
                    // remove that bracket;
                    st.pop();

                    // insert again
                    while( countStar > 0){

                        st.push('*');                        
                        countStar--;
                    }

                }
            }            
        }

        // no more opening brackets are avialable
        if(open == 0) return true;
        
        // Now ew would process for the elememts which are remaining in the stack
        // make count of the star as zero.
        star = 0;        

        while( !st.empty() ){
            
            if(st.top() == '('){
                
                // no stars available to balance;
                if(star == 0) return false;
                // stars available to balance this opening bracket        
                else star--;
            }
            // top is star
            else {
                star++;
            }

            st.pop();

        }

        return true;

    }
};