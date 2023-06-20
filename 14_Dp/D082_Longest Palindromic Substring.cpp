#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// expand from center
class Solution{   
public:
    
    void helper(string &s, int &start, int &end, int l, int r, int n){
        
        while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
        }
        
        l++;
        r--;
        
        if(r - l > end - start) {
            start = l;
            end = r;
        }   
    }

    string longestPalindrome(string s){
        
        int n = s.size();
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < n; i++){
            
            helper(s, start, end, i, i, n); // include center // xyx
            helper(s, start, end, i, i + 1, n); // exclude center // xyyx
            
        }
        
        string ans = "";
        
        for(int i = start; i <= end; i++ ) ans += s[i];
        
        return ans;
    }
};