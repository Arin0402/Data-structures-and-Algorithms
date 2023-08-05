#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

// 1
// sorting and map naive solutions.

// 2
// Floyd's Tortoise and Hare (Cycle Detection)
// Why this algo works  - https://youtu.be/wjYnzkAhcNk?t=542
// In the above video instead of '0' there should be '1' in the loop
// another video
// https://www.youtube.com/watch?v=LUm2ABqAs1w
// O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
                    
        }while(slow != fast);
        
        
        fast = nums[0];
        
        while(slow != fast){
            
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
            
    }
};