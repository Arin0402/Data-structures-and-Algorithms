#include <bits/stdc++.h>
using namespace std;

// sorting and map naive solutions.

// Floyd's Tortoise and Hare (Cycle Detection)
// Why this algo works  - https://youtu.be/wjYnzkAhcNk?t=542
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