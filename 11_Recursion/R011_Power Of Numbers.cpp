#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
// https://www.youtube.com/watch?v=l0YC3876qxg

class Solution{
    public:
    //You need to complete this fucntion
    
    long long helper(int N, int R){
        
        if(R == 0) return 1;
    
        // power is even        
        if(R%2 == 0){
            
            long long temp = helper(N, R/2)%1000000007;
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