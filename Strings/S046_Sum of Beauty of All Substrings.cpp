#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1

// 1
// traverse for all the substrings for size greater than 3
// as size 1 and 2 will result in zero
// calculate the beauty of each substring

class Solution {
  public:
  
    // calculate the beauty of the substring
    int beauty(vector<int> &freq){
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(auto ele : freq){
            
            if(ele != 0){
                mini = min(mini, ele);
                maxi = max(maxi, ele);    
            }
            
        }
        
        return maxi - mini;
    }
    int beautySum(string s) {
        
        // size of string
        int n = s.size();
        
        int ans = 0;
        
        // start for the siez three onwards
        for(int size = 3;  size <= n; size++){
            
            vector<int> freq(26,0);
            
            int l = 0; // left pointer
            int r = size-1; // right pointer
            
            // calculate for the first window
            for(int i = 0; i < size; i++){
                freq[s[i] - 'a']++;
            }
            
            // beauty of the first window
            ans += beauty(freq);
            r++;
            
            // calculate for the rest of the windows
            while(r < n){
                
                freq[s[r] - 'a']++;
                freq[s[l] - 'a']--;
                
                ans += beauty(freq);
                
                r++;
                l++;
            }
            
        }
        
        return ans;
        
    }
};