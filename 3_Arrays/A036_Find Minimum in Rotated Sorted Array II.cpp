#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {

            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high--;
        }

        return nums[low];
    }
};

// 2
// Intution based on the previous question and S002_T_Search in Rotated Sorted Array 2

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int ans = INT_MAX;

        while(low <= high){

            int mid = low + (high - low)/2;

            // Trim down the solution
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                ans = min(ans, nums[low]);
                low++;
                high--;
            }

            // left part is sorted
            else if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]); // taking the minimum from the left part
                low = mid + 1;
            }
            // right part is sorted
            else{
                ans = min(ans, nums[mid]); // taking the minimum from the right part
                high = mid - 1;
            }
            

        }

        return ans;
    }
};