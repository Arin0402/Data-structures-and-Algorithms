#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-window-subsequence/1

// 1
// try all the substrings
// O(N^3)

// 2
// sliding window
// O(N)

class Solution {
  public:
    string minWindow(string str1, string str2) {
        
        // pointers for str1
        int l = 0;
        int r = 0;
        
        // pointers for str2
        int p = 0;
        
        // length of the substring
        int mini = INT_MAX;
        
        // final pointers
        int left = -1;
        int right = -1;
        
        // size of str1
        int n = str1.size();
        
        // size of str2
        int m = str2.size();
        
        while( l < n && r < n){
            
            // found the str2 in substring in str1
            // p is at the last character of str2
            if( p == m-1 && str1[r] == str2[p]){
                
                // update the minimum substring
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    left = l;
                    right = r;
                }
                
                // reset p to 0 as we will start searching for a smaller substring 
                // from the left hand side
                p = 0;
                
                // move by one
                l++;
                
                // move the left pointer while it is not equal to the first character of
                // str2
                while(l < n && str1[l] != str2[0]) l++;
                
                // first character matched so move p by one
                p++;
                
                // l is at the starting of the substring.
                // r is just ahead of it.
                r = l + 1;
                
            }
            // element match
            else if(str1[r] == str2[p]){
                
                // first character
                if(p == 0){
                    
                    // mark the starting of the substring
                    l = r;
                }
                
                // move forward
                r++;
                p++;
                
            }
            
            // no match, so move
            else r++;
            
        }
        
        
        if(left == -1) return  "";
        return str1.substr(left, right - left + 1);
        
    }
};

