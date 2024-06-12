#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/candy/1
// https://www.youtube.com/watch?v=IIqVFvKE6RY

// 1
// O(3N)
// O(2N)

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

// 2
// O(2N)
// O(N)
// by eliminating the right array
class Solution {
  public:
    int minCandy(int N, vector<int> &arr) {
        
        vector<int> count(N, 1);
        
        int sum = 0;
        
        for(int i = 1; i < N; i++){
            if(arr[i] > arr[i-1]) count[i] = 1 + count[i-1];
        }
        
        int curr = count[N-1];
        sum += count[N-1];
        
        
        for(int i = N-2; i >= 0; i--){
            
            if(arr[i] > arr[i + 1]){
                curr++;
                count[i] = max(count[i], curr);
            }
            else curr = 1;
            
            sum += count[i];
        }
        
        return sum;
    }
};
