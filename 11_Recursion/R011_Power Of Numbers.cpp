#include <bits/stdc++.h>
using namespace std;

// 1
// use plain recurcion ->  n*helper(n , r - 1)
// TC - O(R)
// O(R)

// 2
// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
// https://www.youtube.com/watch?v=l0YC3876qxg
// Time Complexity: O(logR) as every time we are dividing R by 2.
// Space Complexity: O(logR) as at most logR recursive calls will be made because we are dividing R by 2 every step.

class Solution{
    public:
    //You need to complete this fucntion
    
    long long helper(int N, int R){
        
        if(R == 0) return 1;
    
        // power is even        
        if(R%2 == 0){
            
            long long temp = helper(N, R/2);
            return ((temp*temp)%1000000007);
        }
        
        // power is odd
        else{
            return (N*helper(N , R-1))%1000000007;
        }
        
    }
    
    long long power(int N,int R)
    {
        return helper(N, R);
    }

};
