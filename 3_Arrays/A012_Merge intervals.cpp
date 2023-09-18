#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-intervals/description/
// naive solution is to compare each interval with rest of the intervals.

// O(nlog(n)) due to sorting.
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
        // sort to make comparisons.
        sort(intervals.begin(), intervals.end());
        
        // store the final vector.
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]); // push the initial interval.
        
        int ind = 0; // index of the interval in ans to which other intervals are comapared.
        
        for( int i =1 ; i < intervals.size(); i++){
                
            vector<int> oldInterval = ans[ind];
            
            // overlaps halfly.
            if(intervals[i][0] <= oldInterval[1] &&  oldInterval[1] < intervals[i][1] ){
                
                ans[ind][1] = intervals[i][1];
            }
            // does not over lap.
            else if (intervals[i][0] > oldInterval[1] ){
                ans.push_back(intervals[i]);
                ind++;
            }
            //  else overlaps completely, no need to do anything.
        }
        
        return ans;
        
    }
};