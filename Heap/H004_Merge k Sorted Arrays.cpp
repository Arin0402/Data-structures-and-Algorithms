#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// N -> total nummber of columns.
// K -> number of rows.

// 1
// merge them one by one
// O(k * k * N) 

// 2
// by compairing the pointers of the arrays.(starting from the first colum)
// O(k * k * N) (k for compairing the elements of each row)

// 3
// divide and conquer techniqe.
// O(N * K * log K).  There are log K levels as in each level the K arrays are divided in half and at each level, the K arrays are traversed.
// O(N * K * log K). In each level O(N * K) space is required.

// 4
// using minheap
// O(N * K * log K)
// O(K)
// This MinHeap based solution has the same time complexity which is O(NK log K). But for a different and particular sized array, this solution works much better. The process must start with creating a MinHeap and inserting the first element of all the k arrays. Remove the root element of Minheap and put it in the output array and insert the next element from the array of removed element. To get the result the step must continue until there is no element left in the MinHeap. 

struct Node{
    
    int data;
    int i;
    int j;
    
    Node(int data, int i, int j){
        this->data = data;
        this->i = i; // row of the element
        this->j = j; // column of the element;
    }
};

class myComparator
{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<Node* , vector<Node*> , myComparator> pq;
        vector<int> ans;
         
        // insert the first node of each row. (total nodes inserted = k)
        for(int i = 0; i < k; i++){
            
            Node* newNode = new Node(arr[i][0], i, 0);
            pq.push(newNode);
        }
        
        while(!pq.empty()){
            
            Node* temp = pq.top();
            pq.pop();
            
            int data = temp->data;
            int i = temp->i;
            int j = temp->j;
            
            ans.push_back(data);
                
            // next element is in the range.
            if(j+1 < k){
                
                Node* newNode = new Node(arr[i][j+1], i, j+1);
                pq.push(newNode);
            }

        }
        
        return ans;
        
    }
};