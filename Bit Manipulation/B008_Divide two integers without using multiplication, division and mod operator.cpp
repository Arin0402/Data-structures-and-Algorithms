#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://youtu.be/zhJt9xIoXCI?t=915

// 1
// subtract one by one
// O(N)

// 2
// O(log(dividend))
class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        
        int sign = ((dividend < 0)^(divisor < 0) ? -1 : 1);
        
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long int quotient = 0, temp = 0;
        
        for(int i = 31; i >= 0; i--){
            
            if(temp + (divisor << i) <= dividend ){
                
                temp += divisor << i;
                quotient += 1<<i;
            }
        }
        
        if(sign < 0)   quotient *= -1;
        
        
        return quotient;
        
    }
};