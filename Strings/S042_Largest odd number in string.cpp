#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1

// 1
class Solution {
  public:
    string maxOdd(string s) {
        
        // start from the back
        // if we find a odd number, the substring form the start till that index 
        // is the answer
        
        int n = s.size();
        int r = n-1;
        
        while(r >= 0){
            
            int ele = s[r] - '0';
            
            if(ele%2 == 1){
                return s.substr(0, r + 1);
            }
            r--;
        }
        
        return "";
        
    }
};