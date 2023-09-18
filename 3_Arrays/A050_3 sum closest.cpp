#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/3-sum-closest/1

// 1
// O(N^2)
// same as before

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        sort(A, A + N);
        
        int mini = INT_MAX; // difference
        int miniSum; // final sum
        
        for(int i = 0; i < N-2; i++){
                
            int l = i+1;
            int r = N-1;
            
            while(l < r){
                
                int sum = A[i] + A[l] + A[r];
                
                if(sum == X){ // found the same sum, so return .
                    
                    return sum;
                }
                else if(sum  < X) l++;
                else r--;
                
                // check and update.
                if( abs(X - sum) < mini ){
                    mini = abs(X - sum);
                    miniSum =  sum ;
                }
                
            }
                    
        }
        
        return miniSum;
        
    }
};