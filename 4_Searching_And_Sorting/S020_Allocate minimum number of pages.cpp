#include <bits/stdc++.h>
using namespace std;

// 1
// can be done using recursion and dp but DON'T TELL THIS SOLUTION
// It will consume a alot of time

// 2
// using binary search
// O(NlogN)
class Solution 
{
    public:
    int minof(int A[], int N){
        
        int mini = A[0];
        
        for(int i =1 ; i < N; i++) mini = min(mini, A[i]);
        
        return mini;
    }
    
    int sumof(int A[], int N){
        
        int sum = 0;
        for(int i =0 ; i < N; i++) sum += A[i];
        
        return sum;
        
    }
    
    bool isPossible(int A[], int N, int M, int mid){
        
        int studentsAlloted = 0;
        int temp = 0;
        
        for(int i =0; i< N; i++){
            
            // every book has to be alloted.
            // if A[i] > mid then not possible
            if(A[i] > mid) return false;
            
            if(temp + A[i] <= mid){
                temp += A[i];
            }
            else{
                studentsAlloted++;
                temp = A[i];
            }
        }
        
        // for last allocation
        if(temp != 0) studentsAlloted++;
        
        return studentsAlloted <= M;
        
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        // low will be the minimum of pages available.
        int low = minof(A,N);
        
        // high will be the sum of all the pages. 
        int high = sumof(A, N);
        
        int res = -1;
        
        // number of students are greater than number of books. so not possible.
        if(M > N) return -1;
        
        while(low <= high){
            
            int mid = low + (high - low) /2;
            
            if(isPossible(A, N, M, mid)){
                
                res = mid;
                
                // check if allocation is possible for the pages lesser than mid.
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return res;
        
        
    }
};