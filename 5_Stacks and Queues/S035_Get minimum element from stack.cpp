#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// https://www.youtube.com/watch?v=V09NfaGf2ao

// 1
// using a stack with pairs
// the second element of the pair would store the minimum element uptill now from the bottom of the stack
// TC - O(1)
// SC - O(2N)   
class Solution{
    
    int minEle = INT_MAX;
    stack<pair<int, int>> s;
    
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           // stack is empty
           if(s.empty()) return -1;
           
           // return the minimum element
           return s.top().second;
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           // empty
           if(s.empty()) return -1;
           
           // return the top
           int val =  s.top().first;
           s.pop();
           
           return val;
           
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           // first element
           if(s.empty()){
               s.push( make_pair(x, x));
           }
           else{
               
               // find the minimum among the x and the previous mini.
               int val = min(x, s.top().second);
               s.push( make_pair(x, val));
               
           }
           
       }
};

// 2
// TC - O(1);
// SC - O(N);
// watch video to understand
class Solution{
    
    int minEle = INT_MAX;
    stack<int> s;
    
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s.empty()) return -1;
           
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
            if(s.empty()) return -1;
            
            // top element of the stack
            int t = s.top();
            s.pop();

            // if the top element is less than the min, then this is our modified value
            // that means the top of the stack is the minimum value uptill now
            if(t < minEle ){

               // minimum value uptill now                 
               int  val = minEle;

               // update the minimum value
               minEle = 2*minEle - t;
               
               return val;
            }

            // else it is not the smallest value, simply return
            else{
                
                return t;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
            // stack empty
            if(s.empty()){
                
                s.push(x);
                minEle = x;
               
            }
            else{
                
                // x is less than minEle
                // push the modified value into the stack
                // whenever we get a value lesser than the minEle, we will always push the modified value
                // in the stack. Not the x in the stack

                if(x < minEle){
                    
                    // why this value?
                    // here x < min
                    // x - min < 0
                    // we need a modified value such that it is less than x
                    // adding x both the sides
                    // 2x - min < x
                    s.push(2*x - minEle);

                    // update minEle
                    minEle = x;
                    
                }
                else s.push(x);
                
            }
       }
};