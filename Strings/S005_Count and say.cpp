#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string Helper(int i, int n, string ans){
        
        // out of bound.
        if(i > n) return ans;
        
        string temp = "";
            
        int cnt = 1; // frequency of character.
        char curr = ans[0]; // first cahracter.
        
        int ind = 1; // start from index 1.
        
        while (ind < ans.size()){
            
            // same character.
            if(ans[ind] == curr){
                cnt++;
            }
            else {
                temp += to_string(cnt); // add count.
                temp += curr; // add character.
                
                // reset.
                cnt = 1; 
                curr = ans[ind];
            }
            
            ind++;
            
        }                
        
        // for the last character.
        temp += to_string(cnt);
        temp += curr;
                        
        return Helper( i+1, n, temp);
                
    }
    
    string countAndSay(int n) {
        
        // start with 2. 
        return Helper(2, n, "1");    
    }
};