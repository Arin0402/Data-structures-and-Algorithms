#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

// 1
// try for all the substrings
// O(N^3)

// 2
// O(N)
// O(26)

class Solution{
    public:
    int longestUniqueSubsttr(string S){
        
        int n = S.size();
        
        vector<int> mp(26, -1);
        
        int maxi = 0;
        
        int l = 0;
        int r = 0;
        
        while(r < n){
            
            char ele = S[r];
            
            // element already exists and it's last occurence lies in the range of l and r
            if(mp[ele - 'a'] >= l){
                
                // find the maximum length
                maxi = max(maxi, r - l);
                
                // update l to index next to the duplicate element
                l = mp[ele - 'a'] + 1;
            }
            
            // either element does not exists or it's last occurence does not lies in 
            // the range of l and r
            else{
                mp[ele - 'a'] = r;
                r++;
            }
        }
        
        // when all the characters are different
        if( l < n){
            maxi = max(maxi , r - l);
        }
        
        return maxi;
        
    }
};