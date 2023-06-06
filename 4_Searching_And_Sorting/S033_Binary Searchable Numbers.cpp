#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/discuss/interview-question/352743/Google-or-Onsite-or-Guaranteed-Binary-Search-Numbers
// https://practice.geeksforgeeks.org/problems/binary-searchable-elements/1

class Solution {
  public:
    int binarySearchable(int Arr[], int n) {
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        // calculate the maximum element on the left of current index
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            left[i] = maxi;
            maxi = max(maxi, Arr[i]);
        }
        
        // calculate the minimum element on the right of current index
        int mini = INT_MAX;
        
        for(int i = n-1; i >= 0; i--){
            right[i] = mini;
            mini = min(mini, Arr[i]);
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            
            if(left[i] < Arr[i] &&  Arr[i] < right[i]) count++;
        }
        
        return count;
        
        
    }
};