#include <bits/stdc++.h>
using namespace std;

// 1
// recursive solution
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string ans = "";
        
        ans += S[0];
        
        char prev = S[0];
        char curr;
        
        int i = 1;
        
        int n = S.size();
        
        while(i < n){
            
            curr = S[i];
            
            if(curr == prev){
                i++;
            }
            else ans += curr;
            prev = curr;
            
        }
        
        return ans;
    }
};