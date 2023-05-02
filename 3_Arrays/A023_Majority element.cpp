#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/majority-element/solution/
// https://www.youtube.com/watch?v=AoX3BPWNnoE

// 1
// traverse each subarray.
// O(n^2)

// 2
// use map
// and check if count is greater than n/2;

// 3
// reciursion
class Solution {
public:
    
    // recurse for left and right part and return the majority element in that subarray.
    // O(nlogn)
    
    int CountEle(vector<int>& nums ,int num,  int low, int high){
        
        int count  = 0;        
        for(int i = low ; i <= high; i++){
            
            if(nums[i] == num) count++;
        }
        
        return count;
    }
    
    int majorityElementRec(vector<int>& nums, int low, int high){
        
        // single element, so this is majority element.
        if( low == high ){ 
            return nums[low];
        }
        
        int mid = (low + high)/2;
        
        int left = majorityElementRec(nums, low, mid);
        int right = majorityElementRec(nums, mid + 1, high);
        
        // both the elements from the left and right part are same, so return any.
        if(left == right) return left; 
        
        // else both the elemts are different so count the appearance of both left and right, and return the element with max count.
        int leftCount = CountEle(nums, left, low, high);
        int rightCount = CountEle(nums, right, low, high);
        
        return (leftCount > rightCount ? left: right);
            
    }
        
    
    
    int majorityElement(vector<int>& nums) {
            
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};

// 4
// Moore voting algorithm
// TC - O(n)
// Sc - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
            
        int count = 0;
        int ele = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            
            if(count == 0){
                
                ele = nums[i];
            }
            
            if(nums[i] == ele) count++;
            else count--;
        }
        
        return ele;
    }
};


