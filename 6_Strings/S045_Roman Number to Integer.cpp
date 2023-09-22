#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

class Solution {
  public:
    int romanToDecimal(string &s) {
        
        unordered_map<char, int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int ans = 0;
        int n = s.size();
        
        for(int i =0 ; i < n; i++){
            
            // if the first value is less than its succeding chararcter, then subtract it from the answer.
            if( mp[s[i]] < mp[s[i+1]] ){
                ans -= mp[s[i]];
            }            
            else ans += mp[s[i]];
        }
        
        return ans;
        
    }
};