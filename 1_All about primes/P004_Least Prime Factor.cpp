#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// TC O( N log(log N))
// We are using two arrays here
// this can be done in a single array also by some comparision

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        
        // array of the elements
        vector<int> arr(n+1);
        for(int i = 0; i <= n; i++) arr[i] = i;
        
        // sieve
        vector<int> sieve(n+1, false);
        for(int i = 0; i <= n; i++) sieve[i] = false;
        
        for(int i = 2; i*i <= n; i++){
            
            // unmarked
            if(sieve[i] == false){
                
                int j = i*i;
                while(j <= n){
                    
                    // unmarked
                    if(sieve[j] == false){
                       sieve[j] = true;
                       
                       // as arr[j] is first time divisible by i, so i
                       // will be it's least prime factor.
                       // update it with i.
                       arr[j] = i;
                    }
                    
                    j += i;
                }
            }
        }
        
        return arr;
    }
};
