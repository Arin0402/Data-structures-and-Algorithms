#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/game-with-string4100/1

// 1
// O(N+Klog(P))  where N is the length of string and P is number of distinct alphabets and K number of alphabets to be removed 
// O(N)

class Solution{
public:

    // idea is to decrease the frequency of the maximum frequecy by one.
    // this has to be done k times.
    
    int minValue(string s, int k){
        
        // max heap to store the distinct elements.
        priority_queue<int> pq;
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < s.size(); i++) freq[s[i]- 'a']++;
        
        // insert the frequency of distinct elements into priority queue.
        for(int i = 0 ; i < 26; i++){
            if(freq[i] > 0) pq.push(freq[i]);
        }
        
        
        for(int i = 0; i < k; i++){
            
            
            int ele = pq.top();
            pq.pop();
            
            // decrease the frequency of the top element by one
            ele--;
            
            // reinsert it.
            pq.push(ele);
            
        }
        
        int ans = 0;
        
        // calculate the answer.    
        while(!pq.empty()){
            
            int ele = pq.top();
            pq.pop();
            
            ans += ele*ele;
        }
        
        return ans;
    }
};