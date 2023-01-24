#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// O(N^2)
class Solution{
public:
    
    // insert element at the bottom of the stack.
    void insert_at_bottom(stack<int> &st, int ele){
        
        if(st.empty()){
            st.push(ele);
            return;
        }
        
        int c = st.top();
        st.pop();
        
        insert_at_bottom(st, ele);
        
        st.push(c);
        
    }
    
    void Reverse(stack<int> &st){
        
        if(st.empty()) return ;
        
        char ele = st.top();
        st.pop();
        
        Reverse(st);
        
        // start inserting elements from the bottom.
        insert_at_bottom(st, ele);
        
    }
};