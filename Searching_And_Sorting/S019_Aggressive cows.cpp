#include <bits/stdc++.h>
using namespace std;

// 1
// use of recursion and try all the possible ways.
// expontential time complexity.

// 2
// we can try starting from distance 1 upto the maximum distance that is possible (i.e maximum element - minimum element).
// for each distance we will run a for loop to check if that distance is valid or not.
// so the TC will be O(n*n);

// 3
// since the distances are in increasing fashion , we can apply binary search.
// our low wil be minimum distance possible i.e 1.
// high will be maximum distance possible.
// try for the distances using binary search.
class Solution {
public:
    
    bool canPlace(vector<int> &stalls, int n, int k, int mid){
        
        // first cow is placed at index 0
        int cnt = 1;
        int currInd = 0;
        
        for(int i = 1; i < n; i++){
            
            // difference is greater than mid
            if(stalls[i] - stalls[currInd] >= mid){
                cnt++;
                currInd = i;
            }
        
        }
        
        // check if the cows count is not less than k.
        return cnt >= k;
        
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        
        // maximum distance would be the largest element.
        int high = stalls[n-1];
        int ans;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(canPlace(stalls, n, k, mid )){
                
                ans = mid;
                
                // increase the distance.
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return ans;
        
    }
};