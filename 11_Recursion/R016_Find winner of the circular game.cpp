// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

#include <bits/stdc++.h>
using namespace std;


// 1
// using circluar linked list
// delete the nodes untill one is left
// O(N*k)


class Node{
    public:

    int data;
    Node* next = NULL;

    Node(int data){
        this->data = data;
    }
};
class Solution {
public:
    int findTheWinner(int n, int k) {                
        
        Node* head = new Node(1);
        Node* temp = head;

        Node* prev = NULL;

        for(int i = 2; i <= n; i++){
            temp->next = new Node(i);  
            prev = temp;
            temp = temp->next;
        }
        
        temp->next = head;
        prev = temp;
        temp = head; 

        while(temp != prev){

            for(int i = 0; i < k - 1; i++){
                prev = temp;
                temp = temp->next;            
            }

            prev->next = temp->next;
            delete temp;

            temp = prev->next;

        }

        return temp->data;
    }
};

// 2
// using queue
// put all the elements in a queue
// rotate the queue for k - 1 times, and then pop the front element
// repeat the above untill only one element is left

// 3
// usign recursion
// leetcode editorial or love babbar's video