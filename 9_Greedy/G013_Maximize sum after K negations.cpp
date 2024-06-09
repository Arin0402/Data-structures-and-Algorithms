#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

// 1
// O(nlogn)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        int countNegatives = 0;
        int n = a.size();

        for(int i = 0; i < n; i++){
            if(a[i] < 0) countNegatives++;
        }
        
        int sum = 0;
        
        
        // all are positive
        if(countNegatives == 0 || k == 0){
            
            // k is even
            if(k%2 == 0){
                for(int i = 0; i < n; i++) sum += a[i];
            }
            
            // k is odd, consume all on the first element
            else{
                
                sort(a.begin(), a.end());
                
                sum += -1*a[0];
                for(int i = 1; i < n; i++) sum += a[i];
            }
        } 
        else{
            
            // both are equal
            if(countNegatives == k){
                for(int i = 0; i < n; i++) {
                    if(a[i] < 0){
                        a[i] = -1*a[i];
                        k--;
                    }
                    
                    sum += a[i];                
                }
            }
            
            // we have more negatives than k
            else if(countNegatives > k){
                
                sort(a.begin(), a.end());
                
                int i = 0;
                for(; i < k; i++) sum += -1*a[i];
                
                for(; i < n; i++) sum += a[i];
                
            }
            // we have less negatives than k
            else{
                
                for(int i = 0; i < n; i++) {
                    if(a[i] < 0){
                        a[i] = -1*a[i];
                        k--;
                    }
                    
                    sum += a[i];
                    
                }
                 
                sort(a.begin(), a.end());
                
                 
                if(k%2 != 0){
                    
                    sum -= a[0];
                    sum += -1*a[0];
                } 
                
            }
            
        }
        
        return sum;
    }
};
