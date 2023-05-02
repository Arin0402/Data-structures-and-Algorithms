#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

// 1
// O(N.log(maxVal)), where maxVal = max(bloomDay)
class Solution {
  public:
    
    // count the number of flowers which will be blommed after mid days
    int flowersBloomed(vector<int> &arr, int M, int K, int mid){
        
        // number of bouquets that can be formed
        int cnt = 0;
        
        // pointer
        int p = 0; 
        int n = arr.size();
        
        // temporary count.
        int temp = 0;
        
        while(p < n){
            
            // will bloom
            if(arr[p] <= mid){
                temp++;
            }
            // streak break
            else temp = 0;
            
            // satisfies condition
            if(temp >= K){
                cnt++;
                temp = 0;
            }
            
            p++;
            
        }
        
        return (cnt >= M);
        
    }
    int solve(int M, int K, vector<int> &bloomDay){
        
        int N = bloomDay.size();
        
        // not possible
        if(N < M*K)
            return -1;
        
        int mini = INT_MAX;    
        int maxi = INT_MIN;
        
        for(auto ele : bloomDay){
            
            mini = min(mini, ele);
            maxi = max(maxi, ele);
            
        }
        
        int low = mini; // minimum days required to bloom first flower
        int high = maxi;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(flowersBloomed(bloomDay, M, K, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
            
        }
        
        return ans;
      
    }
};