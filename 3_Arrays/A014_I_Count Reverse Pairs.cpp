#include <bits/stdc++.h>
using namespace std;

//  https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1
// exactly same as before, just a little change.

// 1
// brute force

// 2
// using merge sort algorithm
class Solution {
  public:
  
    long long int merge(vector<int> &arr, long long int l,long long int m,  long long int r)
    {
        
        long long int i, j, k;
        long long int n1 = m - l + 1;
        long long int n2 =  r - m;
        
        long long int count = 0;
        /* create temp arrays */
        long long int L[n1], R[n2];
    
        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];
    
        
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                
                // Note- Do not use mid here, use length to subtract.
                for(int ind = i ; ind < n1; ind++){
                    // check for the index in the left array where this condition is true.
                    // dry run to get the intution for the given example.
                    if(L[ind] > 2*R[j]){
                        count += n1 - ind;
                        break;
                    }    
                }
                
                j++;
                
            }
            k++;
        }
    
        while (i < n1) arr[k++] = L[i++];
        
        while (j < n2) arr[k++] = R[j++];
        
        return count;
    }
    
    long long int mergeSort(vector<int> &arr, int l, int r)
    {
        
        long long int mid =  l + (r - l )/2 ;
        long long cnt = 0;
        
        if( l < r){
            
            cnt += mergeSort(arr, l , mid);
            cnt += mergeSort(arr, mid + 1 , r);
            
            cnt += merge(arr, l, mid, r);
        }
        
        return cnt;
        
        
    }
    
    int countRevPairs(int n, vector<int> arr) {
        
        return mergeSort(arr, 0, n -1);
    }
};