#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-index3307/1

// 1
// two loops
// O(N^2)

// 2
// A quick observation actually shows that we have been looking to find the first greatest element traversing from the end of the array to the current index. We can see that we are trying to find the first greatest element again and again for each element in the array. Let's say we have an array with us for example [1, 5, 12, 4, 9] now we know that 9 is the element that is greater than 1, 5, and 4 but why do we need to find that again and again. We can actually keep a track of the maximum number moving from the end to the start of the array. The approach will help us understand better and also this improvisation is great to come up with in an interview. 

// - Traverse the array from the end and keep a track of the maximum number to the right of the current index including self
// - Now we have a monotonous decreasing array, and we know we can use binary search to find the index of the rightmost greater element
// - Now we will just use binary search for each of the elements in the array and store the maximum difference of the indices and that's it we are done.

// O(N*logN)
class Solution{
    public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    
    int maxIndexDiff(int A[], int N) 
    { 
        // find the maximum element on the right side for each element
        vector<int> maxTowardsRight(N, 0);
        
        int maxi = A[N-1];
        
        for(int i = N-1; i >= 0; i--){
            
            if(A[i] > maxi) maxi = A[i];
             
            maxTowardsRight[i] = maxi;
        }
        
        // answer
        int ans = INT_MIN;
        
        // calculate the index of the just greater element on the right side for each element 
        for(int i = 0; i < N; i++){
            
            // here we are applying the upper bound on array sorted in decreasing order
            // we can create our binary search function also
            int indexGreater = upper_bound(maxTowardsRight.begin(), maxTowardsRight.end(), A[i], greater<int>()) - maxTowardsRight.begin() - 1 ;
            
            // update the answer
            ans = max(ans, indexGreater - i );
            
        }
        
        return ans;
    }
};

// 3
// O(N)

class Solution{
    public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        
        vector<int> maxTowardsRight(N, 0);
        vector<int> minTowardsLeft(N, 0);
        
        // find the maximum element on the right side for each element
        int maxi = A[N-1];
        
        for(int i = N-1; i >= 0; i--){
            
            if(A[i] > maxi) maxi = A[i];
             
            maxTowardsRight[i] = maxi;
        }
        
        // find the minimum element on the left side for each element
        int mini = A[0];
        
        for(int i = 0 ; i < N; i++){
            
            if(A[i] < mini) mini = A[i];
            
            minTowardsLeft[i] = mini;
            
        }
        
        // answer
        int ans = INT_MIN;
        
        // pointers
        int right = 0;
        int left = 0;
        
        
        while(right < N){
            
            // move the right pointer if the maximum element on right is greater than the minimum element on left 
            if(maxTowardsRight[right] >= minTowardsLeft[left]){
                
                // update the answer
                ans = max(ans, right - left);
                right++;
            } 
            // go to next element
            else left++;
            
        }
        
        return ans;
    }
};
