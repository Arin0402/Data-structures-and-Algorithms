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
    
    int countStudentsAllocated(int arr[], int n, int m, int pages){
        
        int temp = 0;
        
        int i = 0;
        
        int studentAllocated = 0;
        
        while(i < n){
                        
            if(temp + arr[i] <= pages){
                temp += arr[i];
                
            }
            else{
                studentAllocated++;
                temp = arr[i];
            }
            
            i++;
        
        }
        
          // for last allocation
        if(temp != 0) studentAllocated++;
        
        return studentAllocated ;
        
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        
        if(m > n) return -1;
        
        
        // low would be the maximum of all the books
        // why ? -> https://youtu.be/Z0hwjftStI4?t=407
        int low = INT_MIN;
        
        // high would be the sum of all the books
        int high = 0;
        
        for(int i = 0; i < n; i++){
            low = max(low, arr[i]);
        }
        
        for(int i = 0; i < n; i++){
            high += arr[i];
        }
        
        int ans = -1;
        
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            // count students allocated if they can be alloted at max mid pages   
            int students = countStudentsAllocated(arr, n, m, mid);  
            
            
            // less students are alloted so reduce the amount of pages so that the students can increase 
            if(students <= m){
                
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
            
        }
        
        return ans;
        
    }
};
