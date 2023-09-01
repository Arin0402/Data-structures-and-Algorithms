#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/non-overlapping-intervals/1

// 1
// O(Nlogn)
// O(1)

// sorting on the basis of starting time
// consider a case {1,2} and {1,8} so in this case, we would remove the {1,8} as it has the larger endgin time
class Solution {
  public:
  
    static bool cmp(vector<int>& a, vector<int>&b){
        return a[1] < b[1];
    }
    int minRemoval(int N, vector<vector<int>> &intervals) {
        
        // sort on the basis of the ending time.
        sort(intervals.begin(), intervals.end());
        
        // count of removals
        int count = 0;
        
        // previous intrerval
        vector<int> prev = intervals[0];
        
        for(int i = 1; i < N; i++){
            
            // the current inteval's starting time is less than the previous interval's
            // ending time, i.e overlapping
            // so increase the count
            if(intervals[i][0] < prev[1]){
                
                // check the condition, as we have to remove that interval which has larger ending time
                // just this condition is different from the below code
                if(prev[1] >  intervals[i][1] ) prev = intervals[i];
                count++;
                
            }
            
            // else update the previous interval
            else prev = intervals[i];
            
        }
        
        return count;
        
    }
};



// 2
// sorting on the basis of end time
// sorting o
class Solution {
  public:
  
    static bool cmp(vector<int>& a, vector<int>&b){ 
        return a[1] < b[1];
    }
    int minRemoval(int N, vector<vector<int>> &intervals) {
        
        // sort on the basis of the ending time.
        sort(intervals.begin(), intervals.end(), cmp);
        
        // count of removals
        int count = 0;
        
        // previous intrerval
        vector<int> prev = intervals[0];
        
        for(int i = 1; i < N; i++){
            
            // the current inteval's starting time is less than the previous interval's
            // ending time, i.e overlapping
            // so increase the count
            if(intervals[i][0] < prev[1]) count++;
            
            // else update the previous interval
            else prev = intervals[i];
            
        }
        
        return count;
        
    }
};
