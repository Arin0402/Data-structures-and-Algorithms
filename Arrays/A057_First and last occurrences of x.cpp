#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

// 1

// find first occurence
int findLeft(int arr[], int low, int high, int x ){
    
    int res = -1;
    
    while(low <= high){
        
        int mid = low + (high- low)/2;
        
        // go to left even if found the element as there can be more elements.
        if(arr[mid] == x ){
            res = mid;
            high = mid - 1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid  + 1;
        
    }
    
    return res;
        
}

// find last occurence
int findRight(int arr[], int low, int high, int x){
    
    int res = -1;
    
    while(low <= high){
        
        int mid = low + (high- low)/2;
        
        if(arr[mid] == x ){
            res = mid;
            low = mid + 1;
            
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid  + 1;
        
    }
    
    return res;
    
    
}

vector<int> find(int arr[], int n , int x )
{
    
    vector<int> ans(2, -1);
    
    ans[0] = findLeft(arr, 0, n-1, x);
    ans[1] = findRight(arr, 0, n-1, x);
    
    return ans;
    
}