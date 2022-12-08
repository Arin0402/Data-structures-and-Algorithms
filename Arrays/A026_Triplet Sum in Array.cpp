#include <bits/stdc++.h>
using namespace std;

// 1
// try all the triplets.
// three for loops.
// O(n^3)

// 2
// O(N^2) + O(nlogn).
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        // sort the array.
        sort(arr, arr+n);
        
        for(int i = 0 ;i < n - 2 ;i++){
            
            int l = i + 1;
            int r = n - 1;
            
            // two pointer.
            while(l < r){
                
                int sum  = arr[i] + arr[l] + arr[r];
                if(sum == X){
                    return true;
                    
                }
                else if(sum > X) r--;
                else l++;
                
            }
            
        }        
        
        return false;
        
    }
}; 

// 3
// using hashing
// use set.
// TC - O(n^2).
// SC - O(n).
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        
        for(int i =0 ; i < n - 2 ; i++){
            
            unordered_set<int> s;
            int curr_sum = X - A[i];
            
            // This is now two sum question.
            for(int j = i+1; j < n; j++){
                
                if(s.find(curr_sum - A[j]) != s.end()){
                    return true;
                }
                
                s.insert(A[j]);
            }
            
        }
        
        return false;
    }

};


