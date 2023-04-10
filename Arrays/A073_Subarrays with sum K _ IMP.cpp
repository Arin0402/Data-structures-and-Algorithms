#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1
// https://www.youtube.com/watch?v=20v8zSo2v18

// 1
// try all the subarrays
// O(N^2)

// 2
// O(N)
// O(N)
class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        
        unordered_map<int, int> mp;
        
        // for sum zero, count = 1;
        mp[0] = 1;
        
        // current sum
        int currSum = 0;
        
        // answer
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            
            // add it to the answer
            currSum += Arr[i];                        
            
            // add count of all the subarrays to the answer 
            // whose value is equal to currSum - k
            if(mp.find( currSum - k) != mp.end()){
                ans += mp[currSum - k];
            }

            // !--------------NOTE-----------!
            // we have to increase the count for currSum only at the end
            // if we increase the count before, then it will not work for the case
            // ex- 0 0 0 0 0, k = 0            
            mp[currSum]++;
            
        }
        
        return ans;
           
    }
};