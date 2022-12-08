#include <bits/stdc++.h>
using namespace std;

// 1
// Brute force
// for every index find the maximum height on the left and right of it.
// add to the answer =  minimum(left, right) - Height of index. 
// O(n^2)
class Solution{    

    public:    
    long long int getMax(int arr[], int start,  int end){
        
        long long ans = 0;
        
        for(int i = start; i < end; i++) ans = max(ans,(long long ) arr[i]);
        
        return ans;
        
    }
    
    long long trappingWater(int arr[], int n){
        
        long long ans = 0;
        
        for(int i =0 ; i < n ; i++){
            
            long long leftMax = getMax(arr, 0, i ); // left maximum height
            long long rightMax = getMax(arr, i + 1, n ); // right maximum height.
            
            long long Height = min(leftMax, rightMax);
            
            if(Height - arr[i] > 0) ans += Height - arr[i];
            
        }
        
        return ans;
    }
};

// 2
// using prefix and suffix sum.
// this will help in finding the maximum left and right in O(1) time.
// TC - O(n)
// SC - (2n)


// 3
// O(n)
class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        int left = 0;
        int right = n-1;
        
        int leftMax = arr[0];
        int rightMax = arr[n-1];
        
        long long ans = 0;
        
        while(left <= right){
          
            if(arr[left] <= arr[right]){
                
                ans += max( 0 , leftMax - arr[left]);
                leftMax = max(leftMax, arr[left]);
                left++;
                
            }
            else {
                
                ans += max( 0 , rightMax - arr[right]);
                rightMax = max(rightMax, arr[right]);
                right--;
                
            }
        }
        
        return ans;
        
    }
};

