#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/wine-buying-and-selling/1
// https://www.youtube.com/watch?v=ggLUc8HHFvQ
// person will purchase the item from the shop which is closest possible.
// two pointer approach

class Solution{
    public:
    long long int wineSelling(vector<int>& arr, int n){
      
        long long int ans = 0;
        
        int buy = 0;
        int sell = 0;
        
        // find the first buyer index
        for(int i =0; i < n; i++) {
            if(arr[i] > 0){
                buy = i;
                break;
            }
        }
        
        // find the first seller index
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                sell = i;
                break;
            }
        }
        
        while(buy < n && sell < n){
            
            // calculate distance between them
            int distance = abs(buy - sell);
            
            // buyer wants more or equal
            if(arr[buy] >= abs(arr[sell])){
                
                ans += abs(arr[sell])*distance;
                
                arr[buy] -= abs(arr[sell]);
                arr[sell] = 0;
                
            }
            else{
                ans += arr[buy]*distance;
                
                arr[sell] += arr[buy];
                arr[buy] = 0;
              
            }
            
            // move to next buyer and seller if requirement is fulfilled.
            while(buy < n && arr[buy] <= 0) buy++;
            while(sell < n && arr[sell] >= 0) sell++;
               
        }
        
        return ans;
        
      
    }
};

