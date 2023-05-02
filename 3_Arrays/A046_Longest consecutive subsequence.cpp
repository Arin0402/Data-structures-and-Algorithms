#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// 1
// use sorting
// O(nlogn)

// 2
// using map
// https://youtu.be/qgizvmgeyUM?t=199
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        
        // push all the elements in the map.
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++){
            mp[arr[i]]++;
        }
        
        
        int maxi = 0;
        
        for(int i = 0; i < N; i++){
            
            // could not find the element lesser than the current element
            // so the current element is the last element
            if(mp.find(arr[i] - 1) == mp.end()){
                
                int count = 1;
                int val = 1; 
                
                // check for consecutiveness.
                while(mp.find(arr[i] + val) != mp.end()){
                    count++;
                    val++;
                }
                
                maxi = max(maxi, count);
            }
            // else continue
        }
        
        return maxi;
        
    }
};