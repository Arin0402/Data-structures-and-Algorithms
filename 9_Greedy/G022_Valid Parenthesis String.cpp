#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parenthesis-string/description/

// watch strivers solution only for recursion and dp
// https://www.youtube.com/watch?v=cHT6sG_hUZI

// 1
// using recursion
// O(3^N)

// 2
// using dp
// O(N^2)
class Solution {
public:

    vector<vector<int>>* dp;

    bool helper(string &s, int ind, int count, int n){

        if(ind == n) return (count == 0);

        if(count < 0) return false;

        if( (*dp)[ind][count] != -1) return (*dp)[ind][count];

        if(s[ind] == '(') return (*dp)[ind][count] = helper(s, ind + 1, count + 1, n);
        if(s[ind] == ')') return (*dp)[ind][count] = helper(s, ind + 1, count - 1, n);

        return (*dp)[ind][count]=  (
            helper(s, ind + 1, count + 1, n) ||
            helper(s, ind + 1, count - 1, n) ||
            helper(s, ind + 1, count, n)
        );

    }

    bool checkValidString(string s) {

        int n = s.size();

        dp = new vector<vector<int>>(n + 1, vector<int>(n + 1 , -1));

        int i = 0;
        int count = 0;

        return helper(s, i, count, n);              
    }
};

// 3
// O(N)
// O(N)
// https://www.youtube.com/watch?v=KuE_Cn3xhxI
class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();

        stack<int> open;
        stack<int> star;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }

        while(!open.empty() && !star.empty()){

            int openBracketIndex = open.top();
            int starIndex = star.top();

            if(starIndex < openBracketIndex) return false;

            open.pop();
            star.pop();

        }

        if(!open.empty()) return false;

        return true;

    }
};

// 4
// O(N)
// O(1)
// read this
// https://leetcode.com/problems/valid-parenthesis-string/editorial/#approach-4-two-pointer
