#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

// 1
// O(N^3)
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        vector<vector<int>> ans;
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        for(int i = 0; i < n - 3; i++ ){
            
            while(i > 0 && arr[i] == arr[i-1]) i++; // remove duplicates.
            
            for(int j = i + 1; j < n-2; j++ ){
                
                while( j > i + 1 && arr[j] == arr[j-1]) j++; // remove duplicates.
                
                int sum = k - (arr[i] + arr[j]);
                
                int l = j + 1;
                int r = n-1;
                
                while(l < r){
                    
                    if(arr[l] + arr[r] == sum){
                    
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        
                        while( l < r && arr[r] == arr[r-1]) r--;
                        while( l < r && arr[l] == arr[l+1]) l++;
                        
                        l++;
                        r--;
                        
                    }
                    else if (arr[l] + arr[r]  > sum) r--;
                    else l++;
                    
                }
                
            }
        }
        
        return ans;
        
    }
};