#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// solution link and explanation.
//     https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code
    int divide(int dividend, int divisor) {
                
        if(dividend == divisor) return 1;
        
        bool ispositive = (dividend < 0 == divisor < 0);
        
         unsigned int dd = abs(dividend);
         unsigned int dv = abs(divisor);
        
         unsigned int ans = 0 ;
        
        while(dd >= dv){
            
            int q = 0;
            
            while(dd > dv<<(q+1) ){
                q++;
            }
            
            ans += 1<<q;
            
            dd -= dv<<q;
            
        }
        
        if(ans == 1<<31 && ispositive) return INT_MAX;
        
        return ispositive ? ans : -ans;
        
        
        
    }
};