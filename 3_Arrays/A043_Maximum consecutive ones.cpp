#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones/description/

// 1

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int r = 0;

        int maxi = 0;

        while(r < n){

            if(nums[r] == 1){
                r++;
            }
            else{

                maxi = max(maxi , r - l);
                r++;
                l = r;
            }
        }

        if( l != r)  maxi = max(maxi, r - l);

        return maxi;

    }
};
