#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // naive solution is to traverse each substring and check. -- O(N^3);
    
    
    // solution 1 , using set. -- O(2n)
    int solution1(string s){
        
        int left = 0;
        int right = 0;
        int maxlen = 0;
        
        set<int> dic;
        
        while(right < s.size()){
            
            if(dic.find(s[right]) != dic.end()){ // if element is present , increment left and check again.
                
                dic.erase(s[left]);
                left++;
            }
            else{
                
                dic.insert(s[right]);
                maxlen = max(maxlen,  right-left +1);
                right++;
            }
                                    
        }
        
        return maxlen;
        
        
    }
    
    // eficient solution . this directly puts left to its correct position rather than checking one by one.
    int solution2(string s){
        
        int left = 0;
        int right = 0;
        int maxlen =0 ;
        vector<int> vec(256, -1);
        
        while(right < s.size()){
                            
            if(vec[s[right]] != -1) left = max(left , vec[s[right]] + 1);
            
            vec[s[right]] = right;
            maxlen = max(maxlen, right - left + 1);
            
            right++;    
            
        }        
        return maxlen;
        
        
    }
    
    int lengthOfLongestSubstring(string s) {
        
        return solution2(s);
        
    }
};