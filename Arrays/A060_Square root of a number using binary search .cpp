#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/square-root/0

// 1
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        
        if(x == 0 || x == 1 ) return x;
        
        long long int low = 1;
        long long int high = x/2;
        
        long long int ans;
        
        while( low <= high ){
            
            long long int mid = low + (high - low)/2;
            
            long long int sqr = mid*mid;
            
            if(sqr == x) return mid;
            else if(sqr <= x){
                ans = mid;
                low = mid + 1;
            }
            else high = mid -1;
            
        }
        
        return ans;
                
    }
};
