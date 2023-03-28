#include <bits/stdc++.h>
using namespace std;

// this algorithm is used to get all the prime numbers till n
// the naive solution has time complexity of O(N*logn)

// This algorithm has time complexity of O(N*log(logn)) which is almost linear
// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// youtube.com/watch?v=NZ7-ntEgt6g

class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // to keep the track of marked and unmarked elements.
        vector<bool> arr(N+1, false);
        
        for(int i = 2; i <= N; i++){
            
            // not marked
            if(arr[i] == false){
                
                // start from the second multiple.
                int ele = i*2;
                
                while(ele <= N){
                    
                    // mark true.
                    arr[ele] = true; 
                    
                    // increase the multiple.
                    ele += i;
                }
                
            }
            
        }
        
        // elements whick are unmarked forms the answer.
        vector<int> ans;
        
        for(int i = 2; i <= N; i++){
            if(arr[i] == false) ans.push_back(i);
        }
        
        return ans;
        
    }
};