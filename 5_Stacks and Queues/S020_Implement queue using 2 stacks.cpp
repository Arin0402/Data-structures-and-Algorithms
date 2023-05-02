#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

// 1
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
    
public:
    void push(int);
    int pop();
}; 

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()) return -1;
    
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    
    int ele = s2.top();
    s2.pop();
    
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    
    return ele;
}
