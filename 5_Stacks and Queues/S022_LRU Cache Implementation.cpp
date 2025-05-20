#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=z9bJUPxzFOw

struct Node{
    
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int key, int value){
        
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    private:
    
    // {key , node address}
    unordered_map<int, Node*> mp;
    int cap;
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->cap = cap;
        head->next = tail;
        tail->prev = head;   
    }
    
    void deleteNode(Node* temp){
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    
    void addNewNode(int key, int ele){
        
        Node* newNode = new Node(key, ele);
        newNode->next = head->next;
        newNode->prev = head->next->prev;
        head->next->prev = newNode;
        head->next = newNode;
        
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {   
        // key exists in the cache.
        if(mp.find(key) != mp.end()){
            
            // address of the key node in cache.
            Node* temp = mp[key];
            
            // get the value.
            int ele = temp->value;
            
            // delete that node from it's place.
            deleteNode(temp);
            
            // insert that node in the starting
            addNewNode(key, ele);
            
            // update the address.
            mp[key] = head->next;
            
            return ele;
            
        }
        else{
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {   
        // key already present.
        if(mp.find(key) != mp.end()){
           
           // address of the key node in cache.
            Node* temp = mp[key];
            
            // delete that node from it's place.
            deleteNode(temp);
            
            // insert that node in the starting
            addNewNode(key, value);
            
            // update the address.
            mp[key] = head->next; 
            
        }
        // key not present.
        else {
            
            // space available in cache.
            if(mp.size() < cap){
                
                // insert that node in the starting
                addNewNode(key, value);
                
                // update the address.
                mp[key] = head->next;
                
            }
            // space not available , remove the least used key.
            else{
                
                // least used key address.
                Node* temp = tail->prev;
                int oldkey = temp->key;
                
                // remove from map.
                mp.erase(oldkey);
                
                // delete that node from it's place.
                deleteNode(temp);
                
                // insert that node in the starting
                addNewNode(key, value);
                
                // update the address.
                mp[key] = head->next; 
                
            }    
        }
        
        
    }
};