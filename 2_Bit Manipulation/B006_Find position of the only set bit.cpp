#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1


class Solution {
  public:
    int findPosition(int N) {
        
        if(N == 0) return -1;
        
        // if there is only one bit then the result of & operation will be 0.
        // but if there is more than one bit, then it would be greater than 0.
        if((N&(N-1))  > 0) return -1;
        
        int pos = 1;
        
        while(N){
            
            if(N&1 == 1) break;
            
            pos++;
            N >>= 1;
        }
        
        return pos;
        
    }
};      