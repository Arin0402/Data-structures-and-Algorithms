#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// 1
// sort all the elements
// find max length by iterating.
// O(nlogn)

// 2
// priroty queue
// same approach.
// get the top element first to compare with rest of the elements.
// O(nlogn)

// 3
// hashing
class Solution{
  public:
    
    int findLongestConseqSubseq(int arr[], int N)
    {
       int ispresent[100001]; // hash array
       
       fill(ispresent, ispresent + 100001, 0 ); // initialise with 0.
       
       int maxi = INT_MIN; // maximum element of array
       
       for(int i = 0; i < N ; i++ ){ // mark the presence of elements.
           ispresent[arr[i]] = 1;
           maxi = max(maxi , arr[i]);
       }
       
       
       int ptr = 0;
       int ans = 0;
       int count = 0;
       
       while(ptr <= maxi){ // iterate till the maximum element.
           
           // sequence.
           if(ispresent[ptr] == 1) count++;
           
           // sequence got broke.
           else{
               ans = max(ans, count);
               count = 0;
           }
           
           ptr++;
       }
       
       ans = max(ans, count);
       
       return ans;
       
    }
};

// 4
// using map
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        
        unordered_map<int, int> mp;
        
        // insert all the elements in the map
        for(int i  = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        // final ans
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            
            // current element is the first element of the subsequence as other element smaller than this 
            // does not exist in the map
            if(mp.find(arr[i] - 1) == mp.end()){
                
                int val = 1;
                
                while(mp.find(arr[i] + val) != mp.end()) val++;
                
                maxi = max(maxi, val);
            }
        }
        
        return maxi;    
        
    }
};