#include <bits/stdc++.h>
using namespace std;

// O(2^n)
// recursion

// this code is giving Memory limit exceded error
class Solution {
public:

    vector<string> ans;
    unordered_set<string> st;

    int minToRemove(string s){

        int n = s.size();
        int leftCount = 0;
        int rightCount = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') rightCount++;
            else if(s[i] == ')'){
                if(rightCount > 0) rightCount--;
                else leftCount++;
            }            
        }

        return rightCount + leftCount;

    }


    void helper(int ind, int rightCount, int toBeRemoved, string temp, string &s, int n){

        if(st.find(temp) != st.end()) return;

        if(ind == n){
            if(rightCount == 0 && toBeRemoved == 0 && st.find(temp) == st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        if(toBeRemoved < 0) return;

        if(rightCount < 0 ) return;

        if(s[ind] == '('){
            
            // pick
            helper(ind + 1, rightCount + 1,toBeRemoved, temp + '(', s, n);

            // not pick
            helper(ind + 1, rightCount, toBeRemoved - 1, temp, s, n);

        }
        else if(s[ind] == ')'){
            // pick
            if(rightCount > 0)
                helper(ind + 1, rightCount - 1 ,toBeRemoved, temp + ')', s, n);

            // not pick
            helper(ind + 1, rightCount, toBeRemoved - 1, temp, s, n);
        }
        // character
        else{

            helper(ind + 1, rightCount ,toBeRemoved, temp + s[ind], s, n);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        
                
        int n = s.size();

        int toBeRemoved = minToRemove(s);

        string temp = "";

        helper(0, 0, toBeRemoved, temp, s, n);

        return ans;

    }
};
// 2
// TC - 2^N

class Solution {
public:

    // count the number of invalid parenthesis to be removed
    int minToRemove(string s){

        int n = s.size();
        int leftCount = 0;
        int rightCount = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') rightCount++;
            else if(s[i] == ')'){
                if(rightCount > 0) rightCount--;
                else leftCount++;
            }            
        }

        return rightCount + leftCount;

    }


    vector<string> ans;
    unordered_set<string> st;

    void helper(int toBeRemoved, string s){

        // the string has already occured, so we would not process it again
        if(st.find(s) != st.end()) return;
        st.insert(s);

        // check if valid
        if(toBeRemoved == 0) {
            if(minToRemove(s) == 0){
                ans.push_back(s);
                return;
            }
        }

        // try to remove one character.
        for(int i = 0; i < s.size(); i++){

            // left part from the current character
            string left = s.substr(0, i);
            // right part from the current character
            string right = s.substr(i + 1);

            // check for the string after escaping the current character
            helper(toBeRemoved - 1, left + right);

        }
        
    }

    vector<string> removeInvalidParentheses(string s) {
        
        int n = s.size();

        int toBeRemoved = minToRemove(s);

        helper( toBeRemoved, s);

        return ans;

    }
};
