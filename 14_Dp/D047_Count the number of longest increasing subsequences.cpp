#include <bits/stdc++.h>
using namespace std;

// the solution is wrong in the video, just get the intution
// https://www.youtube.com/watch?v=cKVl1TFdNXg

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n , 1);
        vector<int> count(n , 1);
        
        int maxi = 1;

        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = dp[j] + 1;
                        maxi = max(maxi, dp[i]);

                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j] + 1) count[i] += count[j];

                }
            }
        }
        
        int ans = 0;
       
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) ans += count[i];
        }

        return ans;

    }
};
