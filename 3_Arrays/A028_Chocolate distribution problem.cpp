#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

// 1
// generate all the subsets of size m.

// 2
// window based.
// O(nlogn) + O(n)

class Solution{
    
    public:
    
    // we have to keep maximum and minimum as close as possible.
    // so sorting will help in that.
    // we will try every window of size m and compute the answer.
    
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
        sort(a.begin(), a.end());
        
        long long ans = INT_MAX;
        
        for(int i = 0; i < n - m + 1; i++){
            
            long long maxi = a[i + m - 1]; // maximum element of the window.
            long long mini = a[i]; // minimum element of the window.
            
            ans = min(ans, maxi - mini);
        }
    
        return ans;
    }   
};