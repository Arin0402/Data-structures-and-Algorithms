#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// 1
// sliding window technique
// O(n)
// O(k) // window size.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
    queue<long long int> q;
    vector<long long int> ans;
    
    // store the negatives of the first window into the queue.
    for(int i = 0; i < K; i++){
        if(A[i] < 0) q.push(A[i]);
    }
    
    // no element in the queue, push 0.
    if(q.empty()) ans.push_back(0);
    else ans.push_back(q.front());
    
    int end ;
    
    for(int i = 1; i < N-K+1; i++){
        
        end = i + K - 1; // last index of the current window.
        
        // if the last number of the previous window is present in the current queue, then remove it.
        if(A[i-1] == q.front()){
            q.pop();
        }
        
        // push the negative of current window in the queue.
        if(A[end] < 0) q.push(A[end]);
        
        if(q.empty()) ans.push_back(0);
        else ans.push_back(q.front());
        
    }
    
    return ans;
                                                     
}

// 2
// O(n)
// O(1)

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    // index of the first negative integer in the array.
    int ind = 0;
    
    vector<long long int> ans;
    
    // iterate untill we find the first ngative integer.
    while(A[ind] >= 0) ind++;
    
    int start; // starting index of the current window.
    int end ; // ending index.
    
    int i = 0;
    
    // interate for each window.
    while(i < N-K+1 ){
        
        start = i ;
        end = i + K - 1;
        
        // first negative integer is away.
        if(ind > end){
            ans.push_back(0);
            i++;
        }
        
        // first negative integer lies in the current window.
        else if(ind >= start && ind <= end){
            ans.push_back(A[ind]);
            i++;
        }
        // need to find new negative integer.
        else if(ind < start){
            
            ind++;
            while(A[ind] >= 0) ind++;
        }
        
    }
    
    return ans;

 }