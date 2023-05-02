#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// brute force
// store all the contiguous subarray sum and sort.

// 2
// using min heap
// O( N^2 * logk)
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        // minheap.
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < N; i++){
            
            int sum = 0; // get the continuous sub array sum.
            
            for(int j = i; j < N; j++){
                sum += Arr[j];
                
                if(pq.size() < K)  pq.push(sum);
                else if(pq.top() < sum ){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        
        return pq.top();
        
    }
};