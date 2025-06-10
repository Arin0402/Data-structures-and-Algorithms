#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution
{
public:
    int findMin(vector<int> &arr)
    {

        int low = 0;
        int high = arr.size() - 1;

        while (low < high)
        {

            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[high])
                high = mid;
            else
                low = mid + 1;
        }

        // or arr[high] (both are correct)
        return arr[low];
    }
};

// More intutive
// https://www.youtube.com/watch?v=nhEMDKMB44g
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            
            int n = nums.size();
            int low = 0;
            int high = n -1;
            int ans = INT_MAX;

            while(low <= high){

                int mid = low + (high - low)/2;

                // The array is already sorted
                if(nums[low] <= nums[high]){
                    ans = min(ans, nums[low]);
                    break;
                }

                // left part is sorted
                if(nums[low] <= nums[mid]){
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