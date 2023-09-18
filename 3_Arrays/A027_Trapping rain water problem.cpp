#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

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
// using prefix and suffix array.
// this will help in finding the maximum left and right in O(1) time.
// TC - O(n)
// SC - (2n)


// 3
// O(n)
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        
        int l = 0;
        int r = n-1;

        // maximum hright from the left
        long long leftmaxi = INT_MIN  ;

        // maximum height from the right
        long long rightmaxi = INT_MIN;

        long long ans = 0;

        while(l < r){
            
            // left height less than right
            if(leftmaxi <= rightmaxi){
                
                // height is less than leftmaxi and it is less than or equal to the height at right
                // so we can store the water
                if(height[l] < leftmaxi){                    
                    ans += leftmaxi - height[l];
                }
                // update the leftmaxi
                else leftmaxi = height[l];

                // move
                l++;                
            }

            // height at right is less than left
            else{
                
                // height is less than the right maxi
                // so we can store water
                if(height[r] < rightmaxi){
                    ans += rightmaxi - height[r];                    
                }
                // update the right maxi
                else rightmaxi = height[r];

                // move
                r--;
            }

        }
        
        return ans;
    }
};