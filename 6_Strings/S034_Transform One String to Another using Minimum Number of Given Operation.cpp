#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/transform-string5648/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
class Solution
{
    public:
    int transform (string A, string B)
    {
        int n = A.size();
        
        
        // checking if the characters are same or not in the both the strings
        vector<int> count(256, 0);
        
        for(auto ele : A) count[ (int)ele ]++;
        for(auto ele : B) count[ (int)ele ]--;
        
        
        for(int i = 0; i < 256; i++){
            if(count[i] !=  0) return -1;
        }
        
        
        // we will start from the back
        int i = n-1;
        int j = n-1;
        
        int res = 0;
        
        while(i >= 0){
            
            // if the characters mismatch then we will decrease the pointer in A
            // and increase the count
            if(A[i] != B[j]){
                
                i--;
                res++;
                
            }
            // chracters match
            else {
                i--;
                j--;
                
            }
            
        }
        
        return res;
        
        
        
    }
};
