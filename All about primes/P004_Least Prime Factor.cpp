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
        int arr[1001];
        for(int i = 0; i < 1001; i++) arr[i] = i;
        
        // sieve
        bool sieve[1001];
        for(int i = 0; i < 1001; i++) sieve[i] = false;
        
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
        
        // push it into the answer.
        vector<int> ans;
        
        // due to the NOTE given in the problem
        ans.push_back(0);
        
        for(int i = 1; i <= n; i++) ans.push_back(arr[i]);
        
        return ans;
    }
};