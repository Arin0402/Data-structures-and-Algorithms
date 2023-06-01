#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

// O(NlogN) 
class Solution {
public:

    // check if is possible to allocate mid candies to all the children
    bool isPossible(long long int mid, vector<int>& candies, long long int k, int n){
    
        long long int numberofChildrenAllocatedCandies = 0;

        for(int i = 0; i < n; i++){
            numberofChildrenAllocatedCandies += candies[i]/mid;
        }

        return numberofChildrenAllocatedCandies >= k;

    }

    int maximumCandies(vector<int>& candies, long long k) {
        
        int n = candies.size();

        long long int sum = 0;
        for(auto ele : candies) sum += ele;

        long long int low = 1;                
        long long int high = sum/k ;

        long long int ans = 0;

        // binary search on candies
        while(low <= high){
            long long int mid = low + (high - low)/2;

            if(isPossible(mid, candies, k, n)){
                ans = mid;

                // if mid candies can be alloted then mid - 1 candies can also be alloted
                low = mid + 1;                
            }
            else high = mid - 1;

        }

        return ans;

    }
};

