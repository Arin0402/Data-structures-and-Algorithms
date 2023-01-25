#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/queue-reversal/1

// 1
// O(N)
// O(1)
void helper(queue<int> &q){
    if(q.empty()) return;
    
    int ele = q.front();
    q.pop();
    
    helper(q);
    
    q.push(ele);
}

queue<int> rev(queue<int> q)
{
    helper(q);
    return q;
}