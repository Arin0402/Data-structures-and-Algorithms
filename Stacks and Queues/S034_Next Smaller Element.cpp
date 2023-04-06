#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// O(n)
// O(n)
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        vector<int> ans(n, 0);
        
        ans[n-1] = -1;
        st.push(n-1);
        
        for(int i = n-2; i >= 0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i] ) st.pop();
            
            if(st.empty()) ans[i] = -1;
            else ans[i] = arr[st.top()];
            
            st.push(i);
            
        }
        
        return ans;
    } 
};

