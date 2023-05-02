#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-repeating-character-replacement/1
// https://www.youtube.com/watch?v=gqXU1UyA8pk

// 1
// try every subarray
// O(N^2)

// 2
// O(26*N)
// O(26)
// for each window find the frequency of the most frequent character
// if sizeOfWindow - frequency <= k, then we can add more characters to this window
// as the other remaining characters of this window will be flipped.

class Solution {
  public:
    
    // find the most frequent character's frequency
    int findmaxFreq(vector<int> &freq){
        
        int maxi = -1;
        
        for(auto ele : freq) maxi = max(maxi, ele);
        
        return maxi;
        
    }
    
    int characterReplacement(string S, int K) {
        
        int n = S.size();
        
        // to store the frequency
        vector<int> freq(26, 0);
        
        int l = 0;
        int r = 0;
        
        int maxi = -1;
        
        while(r < n){
            
            // current character
            char c = S[r];
            
            // increase the frequency of character
            freq[c - 'A']++;
            
            int maxfreq = findmaxFreq(freq);
            
            int size = r - l + 1;
            
            // can accomodate more characters
            if(size - maxfreq <= K) r++;
            else{
                
                // update the maxi
                maxi = max(maxi, r - l);
                
                // decrease the frequency of the left character
                c = S[l];
                freq[c - 'A']--;
                
                // increase the left pointer
                l++;
                
                // also increase the right pointer as we have already increased the frequency
                // for the rth cahracter
                r++;
            }
        }
        
        // for last window
        if(l < n) maxi = max(maxi, r - l);
        
        return maxi;
        
    }
};


