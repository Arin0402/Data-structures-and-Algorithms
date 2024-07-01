#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1

class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    
	    // left and right pointers of final subarray
	    int l = 0;
	    int r = 0;
	    
	    // maximum sum
	    int maxi = 0;
	    
	    // maximum length og hte subarray
	    int maxlen = 0;
	    
	    // temporary sum
	    int temp = 0;
	    
	    // temporary left index of subarray
	    int khamila = 0;
	    
	    for(int i = 0; i < n; i++){
	        
	        // negative number
	        if(a[i] < 0){
	            
	            if(temp > maxi){
	                maxi = temp;
	                maxlen = i - khamila;
	                r = i-1;
	                l = khamila;
	                
	            }
				// sum is same but length is different
	            else if(temp == maxi && i - khamila > maxlen){
	                maxlen = i - khamila;
	                l = khamila;
	                r = i-1;
	            }
	            
	            khamila = i + 1;
	            
	            // reset
	            temp = 0;
	            
	        }
	        else{
	            temp += a[i];
	        }
	        	        
	    }
	    
	    // for the last case
	    if(temp >= 0){
	        
	        if(temp > maxi){
                maxi = temp;
                maxlen = n - khamila;
                r = n-1;
                l = khamila;
                
            }
            else if(temp == maxi && n - khamila > maxlen){
                maxlen = n - khamila;
                l = khamila;
                r = n-1;
            }
	    }
	    
	    // final answer
	    vector<int> ans;
	    
	    for(int i = l; i <= r; i++){
	        ans.push_back(a[i]);
	    }
	    
	    return ans;
	    
	}
};