#include <bits/stdc++.h>
using namespace std;

// interviewbit.com/problems/counting-subarrays/
// https://www.youtube.com/watch?v=L_yBEqBAZzs
// easy

// 1
// O(N^2)
// two for loops

// 2
// using two pointers
// O(N)
int solve(vector<int> &A, int B) {
    
    int ans =0;
    
    int l = 0;
    int r = 0;
    
    int sum = 0;
    
    int n = A.size();
    
    while(r < n){
        
        sum += A[r];
        
        while(sum >= B){        
            sum -= A[l++];
        }
        
        ans += r - l + 1;
        
        r++;
                
    }
    
    return ans;
        
}
