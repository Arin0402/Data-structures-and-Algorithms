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
        // deque for inserting indexes
        // we will maintain the elements in  decreasing order so that
        // we get the largest element for a particular window at the begining of the queue
        deque<int> dq;
        
        // answer vector
        vector<int> ans;
        
        // for the first window
        for(int i = 0; i < k; i++){
            
            // remove the elemens of the deque if they are smaller than the current element
            while(!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
            
            // insert the current element's index
            dq.push_back(i);
        }
        
        // insert the answer for the first window
        ans.push_back(arr[dq.front()]);
        
        // for all the windows
        for(int start = 1; start < n - k + 1; start++){
            
            // ending index
            int end = start + k - 1;
            
            // check if the front element of queue is part of the current window or not
            // if not, then remove it
            if(!dq.empty() && dq.front() < start) dq.pop_front();
            
            // remove the elements of the deque if they are smaller than the current element
            while(!dq.empty() && arr[dq.back()] < arr[end] ) dq.pop_back();
            
            // insert the current element's index
            dq.push_back(end);
            
            // add the front element into the answer
            ans.push_back(arr[dq.front()]);
            
        }
        
        return ans;
    }
};