#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

// 1
// using two queues.
// making pop operation costly
// O(1) -> push
// O(N) -> pop
// O(1) -> space

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.size() == 0) return -1;
    
    while(q1.size() > 1){
        int ele = q1.front();
        q1.pop();
        q2.push(ele);
    }
    
    int ele = q1.front();
    q1.pop();
    
    while(!q2.empty()){
        int ele = q2.front();
        q2.pop();
        q1.push(ele);
    }
    
    return ele;
}

// 2
// implementing stack using single queue only.
// https://youtu.be/jDZQKzEtbYQ?t=433
