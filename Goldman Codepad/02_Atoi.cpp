// https://leetcode.com/problems/string-to-integer-atoi/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int myAtoi(string s) {
    
            int n = s.size();
            // by default sign is positive
            int sign = 1;
    
            int i = 0;
    
            // escape the white space
            while(s[i] == ' ') i++;
    
    
            // Find the sign
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+') i++;        
    
            int base = 0;
    
            while(s[i] >= '0' && s[i] <= '9'){
                
                // if base is already greater than the INT_MAX/10 then adding any digit to it would also result in greater value than INT_MAX
                if(base == INT_MAX/10 && s[i] - '0' > 7 || base > INT_MAX/10){
                    if(sign == 1) return INT_MAX;
                    return INT_MIN;
                }
                
                base = base*10 + (s[i] - '0');
                i++;
            }
    
            return base*sign;
    
        }
    };