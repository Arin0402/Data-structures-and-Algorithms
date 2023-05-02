#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1 
// try all the subarrays
// O(N*k)

// 2
// using deque
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        // store the result in decreasing fashion in deque.
        deque<int> dq;
        vector<int> ans;
        
        // compute for the first sliding window.
        for(int i = 0; i < k; i++){
            
            // remove all the elements from the back in deque which are smaller than the current element.
            while(!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
            dq.push_back(i);
            
        }
        
        ans.push_back(arr[dq.front()]);
        
        // for rest of the windows
        int start = 1;
        int end = k ;
        
        while(end < n){
            
        
            if(!dq.empty() && dq.front() < start){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[end] >= arr[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(end);
            
            ans.push_back(arr[dq.front()]);
            
            
            start++;
            end++;
        }
        
        return ans;
    }
};