#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/count-substring/1

// 1
// try all the substrings
// O(N^2)

// 2
// sliding window
// O(N)
// O(1) (constant space as the string contains only three characters a,b,c)
class Solution {
  public:
    int countSubstring(string s) {
        
        // size of the string
        int n = s.size();
        
        // answer
        int count = 0;
        
        // map
        unordered_map<char, int> mp;
        
        // pointers
        int l = 0;
        int r = 0;
        
        while(r < n){
            
            // increase the frequency
            mp[s[r]]++;
            
            // current substring have count of a,b,c greater than 0
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                
                // add all the substrings to the answer for which the current substring
                // is the prefix
                // ex - abcabc
                // now if we got the substring abc, then add abc, abca, abcab, abcabc
                // total count = 4, which is equal to (n - r) i.e 6 - 2
                // 6 is the size of the string, r is the right pointer
                count += n - r;
                
                // slide the window
                mp[s[l]]--;
                l++;
            }
            
            // move
            r++;
            
        }
        
        return count;
    }
};