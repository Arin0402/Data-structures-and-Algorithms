#include <bits/stdc++.h>
using namespace std;

// 1
// naive solution
// O(N^2)

// 2
// O(N)

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {   
        
        int n = s.size();
        int m = p.size();
        
        // store the frequencies of characters of s
        vector<int> freqS(26, 0);
        
        // store the frequencies of characters of p
        vector<int> freqP(26, 0);
        
        // calculate the frequncies of the characters in p
        for(auto c : p) freqP[c - 'a']++;
        
        // pointers
        int l = 0;
        int r = 0;
        
        // count of elements in p.
        int count = 0;
        
        int mini = INT_MAX;
        int left = -1;
        int right = -1;
        
        while(r < n){
            
            // character of s
            char ele = s[r];
            
            // ele is present in p
            if(freqP[ele - 'a'] > 0){
                
                // frequency of ele in freqP is greater than that in freqS
                if(freqS[ele - 'a'] < freqP[ele - 'a']) 
                    count++;
                
                freqS[ele - 'a']++;
            }
            
            // got all the characters in the current substring
            if(count == m){
                
                while(count == m){
                    
                    // update the maxi
                    if(r - l + 1 < mini){
                        mini = r - l + 1;
                        left = l;
                        right = r;
                    }
                    
                    // left most character
                    ele = s[l];
                    
                    // ele is present in p
                    if(freqP[ele - 'a'] > 0){
                        
                        // frequency of ele in freqS is  <= that in freqP
                        if(freqS[ele - 'a'] <=  freqP[ele - 'a'] ){
                            count--;
                        }
                        
                        freqS[ele - 'a']--;
                    }
                    
                    l++;
                    
                }
            }
            
            r++;
        }
        
        if(left == -1) return "-1";
        
        return s.substr(left, right - left + 1);
        
    }
};