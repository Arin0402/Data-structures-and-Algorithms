#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// https://www.youtube.com/watch?v=CZQGRp93K4k

// 1
// naive checking
// O(N^2)

// 2
// O(N)
// O(N)
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
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
        
        int end;
        
        for(int i = 1; i < n-k+1; i++){
            
            end = i + k -1;
            
            if(!dq.empty() && dq.front() < i){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[end] >= arr[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(end);
            
            ans.push_back(arr[dq.front()]);
            
        }
        
        return ans;
        
    }
};