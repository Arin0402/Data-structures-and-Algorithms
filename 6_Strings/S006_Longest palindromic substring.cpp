#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

// 1
// TC - O(n^2)
// SC - O(1)

class Solution {
  public:
  
    string longestPalin (string S) {
        
        // Idea is to expand from each element towards left and right and find the maximum
        // length palindrome.
              
        int n = S.size();
        
        // final indexes.
        int start = 0; 
        int end = 0;
        
        // longest length.
        int longestLength = 0;
        
        int l, h;
        
        // try out for both even and odd length substrings.
        
        for(int i = 1; i < n; i++){
            
            // even substring.
            
            l = i-1;
            h = i;
            
            while(l >= 0 && h < n && S[l] == S[h]){
                
                if(h-l + 1 > longestLength ){
                    longestLength = h - l +1;
                    start = l;
                    end = h;
                    
                }
                
                l--;
                h++;
            }
            
            
            // odd substring
            
            l = i-1;
            h = i+1;
            
            while(l >= 0 && h < n && S[l] == S[h]){
                
                if(h-l + 1 > longestLength ){
                    longestLength = h - l +1;
                    start = l;
                    end = h;
                    
                }
                
                l--;
                h++;
            } 
            
        }
        
        string ans = "";
        
        for(int i = start ; i <= end; i++) ans+= S[i];
        
        return ans;
        
    }
};