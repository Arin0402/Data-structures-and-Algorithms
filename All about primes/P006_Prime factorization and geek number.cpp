#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/prime-factorization-and-geek-number1915/1

// 1
// O(sqrt(N))

class Solution{
public:
    int geekNumber(int N){
        
        // start from 2
        int i = 2;
        
        // run till the sqaure root of N
        while( i*i <= N){
            
            // keep the count for the current i
            int count = 0;
            
            while(N%i == 0){
                
                N = N/i;
                count++;
            }
            
            // i is dividing N more than one time, so return false.
            if(count > 1) return 0;
            i++;
        }
        
        return 1;
        
    }
};