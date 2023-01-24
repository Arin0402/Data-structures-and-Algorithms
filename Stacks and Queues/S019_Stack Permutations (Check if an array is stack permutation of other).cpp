#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stack-permutations/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// O(N)
// O(N)
class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack<int> st;
        int n = A.size();
        
        int j = 0; // B vector pointer
        
        for(int i = 0; i < n; i++){
            
            // push the A[i] in the stack.
            st.push(A[i]);

            // if top of stack becomes equal to the B[j] , the pop and increase the pointer
            while(!st.empty() && st.top() == B[j]){
                st.pop();
                j++;
            }
            
        }
        
        if(st.empty()) return true; // all the elements matched
        return false;
    }
};