#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// O(n)

class Solution {
public:
    
    // at the end number of zeros should be equal to number of ones.
    // so at any moment they are equal then we have got the substring.
    
    int maxSubStr(string str){
        
        int n = str.size();
        int cntZero = 0;
        int cntOne = 0;
        
        int ans = 0;
        
        for(int i = 0; i< n; i++){
            
            if(str[i] == '0') cntZero++;
            else cntOne++;
            
            if(cntZero == cntOne) ans++;
        }
        
        if(cntZero != cntOne) return -1;
        
        return ans;
    }
};
