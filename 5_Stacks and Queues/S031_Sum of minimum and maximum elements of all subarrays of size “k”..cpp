#include <bits/stdc++.h>
using namespace std;

// same as previous 
// https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=1
// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
// we have just use another deque to for finding the minimum element in the subarray.
// we store the elements in increasing fashion in this deque

// 1
// O(n)
// O(k)

long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	
	// store the result in decreasing fashion in deque.
        deque<int> dqMax, dqMin;        

        long long int ans = 0;
        // compute for the first sliding window.
        for(int i = 0; i < k; i++){
            
            // remove all the elements from the back in deque which are smaller than the current element.
            while(!dqMax.empty() && arr[i] >= arr[dqMax.back()]) dqMax.pop_back();
			while(!dqMin.empty() && arr[i] <= arr[dqMin.back()]) dqMin.pop_back();
            dqMax.push_back(i);
			dqMin.push_back(i);
            
        }

		ans += arr[dqMax.front()] + arr[dqMin.front()];
                        
        int end;
        
        for(int i = 1; i < n-k+1; i++){
            
            end = i + k -1;
            
            if(!dqMax.empty() && dqMax.front() < i){
                dqMax.pop_front();
            }
			if(!dqMin.empty() && dqMin.front() < i){
				dqMin.pop_front();
			}

            while(!dqMax.empty() && arr[end] >= arr[dqMax.back()]){
                dqMax.pop_back();
            }
            while (!dqMin.empty() && arr[end] <= arr[dqMin.back()]) {
              	dqMin.pop_back();
            }

            dqMax.push_back(end);
			dqMin.push_back(end);                        
            
			ans += arr[dqMax.front()] + arr[dqMin.front()];
        }
        
        return ans;
        
}
