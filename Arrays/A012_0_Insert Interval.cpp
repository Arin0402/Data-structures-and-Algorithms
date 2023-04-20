#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/insert-interval-1666733333/1

// 1
// O(N)
class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        
        // final answer
        vector<vector<int>> ans;
        
        for(int i = 0; i < N; i++){
            
            // newEvent is before the current interval
            if(intervals[i][0] > newEvent[1]){
                ans.push_back(newEvent);
                
                // insert the rest of the elements
                for(; i < N; i++) ans.push_back(intervals[i]);
                
                // return
                return ans;
            }
            // current interval is before the new event
            else if(intervals[i][1] < newEvent[0]){
                
                // insert the current interval
                ans.push_back(intervals[i]);
            }
            // else overlapping
            else {
                
                // update the newEvent
                newEvent[0] = min(newEvent[0], intervals[i][0]);
                newEvent[1] = max(newEvent[1], intervals[i][1]);
            }
        }
        
        // insert the newEvent if all the intervals appear before the newEvent or
        // merging is done till the end
        ans.push_back(newEvent);
        
        return ans;
        
    }
};