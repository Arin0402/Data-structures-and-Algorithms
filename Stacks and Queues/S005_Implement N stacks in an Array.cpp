#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=1

// have to watch video to understand.
// https://www.youtube.com/watch?v=9x7TYLP3714

class NStack
{
public:

    int *arr;
    int *top;
    int *next;
    int free = 0;
    int i;

    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for(int i = 0; i < N; i++) top[i] = -1;
        for(int i = 0; i < S-1; i++) next[i] = i+1;
        next[S-1] = -1;
    }

    // check if array is full or not
    bool isFull(){
        if(free == -1) return true;
        return false;
    }

    // if taht particular stack is empty or not.
    bool isEmpty(int m){
        if(top[m] == -1) return true;
        return false;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        m -= 1;
        // array is full.
        if(isFull()) return false;

        i = free;
        free = next[i];

        next[i] = top[m];
        top[m] = i;

        arr[i] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        m -= 1;

        if(isEmpty(m)) return -1;

        i = top[m];

        top[m] = next[i];

        next[i] = free;
        free = i;

        return arr[i];
    }
};