#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int point = 1;
        int num = nums[0];
        
        for(int i = 1 ;i < nums.size(); i++){
            
            if(nums[i] == num) continue;
            
            nums[point] = nums[i];
            num = nums[i];
            point++;
            
        }
        
        return point;
    }
};