#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=1

// 1
// using another stack
// O(n)
// O(n)

// 2
// using recursion
// O(n)
// O(n)
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{

    if (myStack.empty()) {
        myStack.push(x);
        
        return myStack;
    }
    else {

        int a = myStack.top();
        myStack.pop();

        pushAtBottom(myStack, x);

        myStack.push(a);
    }

    return myStack;
}
