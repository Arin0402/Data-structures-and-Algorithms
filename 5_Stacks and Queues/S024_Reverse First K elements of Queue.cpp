#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// 1
// O(N)
// O(N)

queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int> st;
    int n = q.size();
    
    // insert first k elements into the stack.
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }
    
    // insert those elements back to the queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    // insert the remaining elements from the start of the queue to the back of the queue.
    for(int i = k; i < n; i++ ){
        q.push(q.front());
        q.pop();
    }
    
    return q;   
    
}