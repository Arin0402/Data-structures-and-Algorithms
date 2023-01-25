#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=1

void interLeaveQueue(queue< int > & q) {
    
    queue<int> q1;

    int n = q.size();

    // inseert the first half eelements into q1.
    for(int i =0; i < n/2; i++){
        q1.push(q.front());
        q.pop();        
    }

    // pick one element from q1 and one from q, then push into q.
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }


}