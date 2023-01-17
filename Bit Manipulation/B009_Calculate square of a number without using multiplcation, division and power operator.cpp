#include <bits/stdc++.h>
using namespace std;

// Calculate square of a number without using *, / and pow()
// https://www.codingninjas.com/codestudio/problems/calculate-square-of-a-number_1112623?leftPanelTab=0
// https://www.youtube.com/watch?v=pOKuLSKnAW4

// 1
// simple solution is to add the number n to the answer n times.
// O(n)

// 2
// O(logn)
int calculateSquare(int num)
{   
    // num will be used to find the set bit positions.
    num = abs(num);    
    
    int n = num; // to multiply.
    int ind = 0; // positions of the set bits.
    
    int ans = 0;
    
    while(num){
        
        if((num&1) == 1){            
            ans += n << ind;  // (n * (2^ind) )
        }
        
        ind++; // increase the index.
        num = num >> 1; // left shift the num by one.
    }
    
    return ans;
    
    
}