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