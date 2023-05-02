#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// 1
// try all the substrings
// O(N^3)

// 2
// sliding window
// O(N)
// O(k)

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    
        int n = s.size();
        unordered_map<char, int> mp;
        
        int l = 0;
        int r = 0;
        
        int maxi = -1;
        
        while(r < n){
            
            // less than k elements
            if(mp.size() < k){
                
                // increase the count
                mp[s[r]]++;
                r++;
            }
            // mp cantains k elements and
            // character is already present
            else if(mp.size() == k && mp.find(s[r]) != mp.end() ){
                
                // increase the count
                mp[s[r]]++;
                r++;
            }
            
            // mp cantains k elements and
            // character is not present
            else if(mp.size() == k){
                
                // update the answer
                maxi = max(maxi, r - l);
                
                // include it into the map
                mp[s[r]]++;
                        
                // remove elements from left
                while( mp.size() > k){
                    
                    // decrease the count
                    mp[s[l]]--;
                    
                    // if count is zero, then erase it from the map
                    if(mp[s[l]] == 0) mp.erase(s[l]);
                    
                    l++;
                }
                
                // move
                r++;
            }
            
        }
        
        // for last window
        if(l < n && mp.size() == k) maxi = max(maxi, r - l);
        
        return maxi;
        
    }
};