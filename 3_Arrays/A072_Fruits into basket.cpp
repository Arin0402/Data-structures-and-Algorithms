#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

// 1
// try every subarray
// O(N^2)

// 2
// sliding window appraoch
// O(2*N)

// we have to find the longest subarray which have only two type of elements

class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        // first fruit type
        int firstfruit = -1;
        
        // second fruit type
        int secondfruit = -1;
        
        // index of the first occurence of the second fruit type
        int secondfruitIndex = -1;
        
        int l = 0;
        int r = 0;
        
        int maxi = -1;
        
        while(r < N){
            
            int fruit = fruits[r];
            
            // fruit matches.
            if( fruit == firstfruit || fruit == secondfruit ) r++;
            
            // first time assigning
            else if(firstfruit == -1){
                firstfruit = fruit;
                r++;
            }
            // first time assigning
            else if(secondfruit == -1 ){
                secondfruit = fruit;
                secondfruitIndex = r;
                r++;
            }
            // does not match
            else{
                
                // update the maxi
                maxi = max(maxi, r - l);
                
                // firstfruit  = secondfruit;
                // secondfruit = fruit;
                
                // l = secondfruitIndex;
                
                l = r-1;
                
                firstfruit = fruits[l];
                secondfruit = fruit;
                
                while(fruits[l] == firstfruit ) l--;
                l++;
                
                // while(fruits[])
                // secondfruitIndex = r;
                
                r++;
            }
            
        }
        
        if(l < N) maxi = max(maxi, r - l);
        
        
        
        return maxi;
        
    }
};
