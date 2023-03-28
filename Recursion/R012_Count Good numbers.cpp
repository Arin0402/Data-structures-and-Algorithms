#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-good-numbers/description/
// Good question 
// based on previous questoin(power of numbers)

// explanation
// for example if n = 4
// then solution would be 5*4*5*4  (5 for even place, 4 for odd place)
// this can be written as 20*20
// or 20^20. This reduces to power question

// if n = 5
// then solution would be 5*4*5*4*5  (5 for even place, 4 for odd place)
// this can be written as 5*20*20
// or 5*(20^20). This reduces to power question

class Solution {
public:

    // to find the power of a number
    long long int helper(long long n, long long r){

        if(r == 0) return 1;

        if(r%2 == 0){

            long long temp = helper(n, r/2);
            return (temp*temp)%1000000007;
        }
        else{
            return (n*helper(n, r-1))%1000000007;
        }

    }

    int countGoodNumbers(long long n) {

        if(n == 1) return 5;
        if(n == 2) return 20;

        // odd
        if(n%2 == 1){
            return (5*helper(20, (n-1)/2))%1000000007;
        }
        // even        
        else return helper(20, n/2)%1000000007;
    }
};