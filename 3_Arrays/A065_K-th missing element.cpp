#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1

// 1
// O(n)
int KthMissingElement(int arr[], int n, int k)
{
    // ex - 38 42 50 60 , k = 2, ans = 40    
    int cnt = 0; // count the number 
    int num = arr[0]; // starting element                       
    
    int j = 0;
    
    while(j < n){
        
        // number match
        if(arr[j] == num){
            num++;
            j++;
        }
        else{
            
            // increase the count
            cnt++;
            
            // found the desired.
            if(cnt == k) return num;
            
            // increase the num
            num++;
        }
        
    }
    
    return -1;
    
}

// 2
// O(logn)
// using binary search
// https://www.youtube.com/watch?v=uZ0N_hZpyps
// use the index and the value at that index to compare how many elements are missing at that particular index( this index is mid)
// if the number of values missing at the mid is lesser than k then we move to right otherwise we go left.
// at the end, we would find two indexes between which the answer will lie.
int KthMissingElement(int a[], int n, int k)
{
    if(n == 1) return -1;
    
    int low = 0;
    int high = n - 1;
    
    int firstEle = a[0];
    
    while(low <= high){
        
        int mid = low + (high - low)/2;
        
        int valueDiff = a[mid] - firstEle;

        // number of missing elements are greater than k at mid
        if(valueDiff - mid >= k) high = mid - 1;
        else low = mid + 1;
        
    }
    
    int diff = a[high] - firstEle - high;

    // if there is no element missing ( completely sorted array, we return -1)
    return (a[high] + (k - diff) < a[n-1] ?  a[high] + (k - diff) : -1 );
    
    
}
