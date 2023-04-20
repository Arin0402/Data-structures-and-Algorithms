#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/candy/1

// 1
// O(N)
// O(N)

class Solution {
  public:
    
    // we divide the problem into two sub problems 
    // for the first sub problem, consider we need to give more candies to the child, if he have more 
    // rating then the left child
    // similarly for the second problem, consider we need to give more candies to the child, if he have more 
    // rating then the right child
    // at the end , we will take the maximum of both the values for each index.
    
    int minCandy(int N, vector<int> &ratings) {
        
        // for left to right
        vector<int> left(N, 1);
        
        // for right to left
        vector<int> right(N, 1);
        
        for(int i = 1; i < N; i++){
            // current rating is greater than the left child
            if(ratings[i] > ratings[i-1]) left[i] =  left[i-1] + 1;
        }
        
        for(int i = N-2; i >= 0; i--){
            // current rating is greater than the right child
            if(ratings[i] > ratings[i+1]) right[i] =  right[i+1] + 1;
        }
        
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            ans += max(left[i], right[i]);
        }
        
        return ans;
    }
};
