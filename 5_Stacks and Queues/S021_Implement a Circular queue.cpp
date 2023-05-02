#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-circular-queue/description/

class MyCircularQueue {
public:

    int *arr;
    int front = -1;
    int rear = -1;

    int k;

    MyCircularQueue(int k) {
        arr = new int[k];
        this->k = k;
    }
    
    bool enQueue(int value) {        

        if(isFull() == true)  return false;

        // no element.
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = value;
            return true;
        }
        // elements are there.
        else{
            rear = (rear + 1)%k ;            
            arr[rear] = value;
            return true;
        }

    }
    
    bool deQueue() {
        
        // no element.
        if(rear == -1) return false;

        // only one element.
        if(front == rear){
            arr[front] = 0;
            front = rear = -1;            
        }
        // more than one element.
        else{
            arr[front] = 0;
            front =  (front+1)%k;
        }
        
        return true;
    }
    
    int Front() {

        if(front == -1) return -1;
        return arr[front];
    }
    
    int Rear() {
        
        if(rear == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {

        if(front == -1 && rear == -1) return true;        
        return false;
    }
    
    bool isFull() {
                
        if(front != -1 && rear != -1 && (rear+1)%k == front) return true;
        return false;        
    }
};
