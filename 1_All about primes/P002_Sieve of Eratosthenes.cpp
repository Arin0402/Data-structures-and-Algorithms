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
        
        // why i*i ?
        // if we consider the dividsors of 30
        // 2, 15 where the minimum of 2, 15 is 2 and it is less than sqrt of 30
        // 3, 10 where the minimum of 3, 10 is 3 and it is less than sqrt of 30
        // 5, 6 where the minimum of 5, 6 is 5 and it is less than sqrt of 30

        // so the prime factors of 30 are less than sqrt of 30 and 15, 10, 6 will be marked by these numbers(2,3,5) 
        // for a number which is greater than the sqrt of 30. if it is prime then it will be unmarked
        // and if it is not not prime then it will get marked
        // for example 7, 7 is prime so it will remain unmarked.

        for(int i = 2; i*i <= N; i++){
            
            // not marked
            if(arr[i] == false){
                
                // start from the square of the i.
                // the 2,3.. etc multiples of i will be already marked by the numbers less than i
                int ele = i*i;
                
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