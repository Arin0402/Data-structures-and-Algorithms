#include <bits/stdc++.h>
using namespace std;

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
