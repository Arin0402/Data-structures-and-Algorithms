#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

// for K largest elements , use min heap
// for K smallest elements use max heap.

// most efficient solution
// O(N + KlogK)
// O(K+(N-K)*logK)
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    
	    priority_queue<int, vector<int> , greater<int>> pq;
	    
	    for(int i = 0; i < k; i++){
	        pq.push(arr[i]);
	    }
	    
	    for(int i = k; i < n; i++){
	        
	        if(arr[i] > pq.top()){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!pq.empty()){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	    
	}

};