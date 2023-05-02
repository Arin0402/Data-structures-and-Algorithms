#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// 1
// O(n)
// O(n + 26)
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    // to store the frequency.
		    vector<int> freq(26, 0);
		    
		    // to store the order of characters.
		    queue<char> q;
		    
		    string ans = "";
		    
		    for(int i = 0; i < A.size(); i++){
		        
		        freq[A[i] - 'a']++; // increase the frequency.
		        q.push(A[i]); // push the character in queue.
		        
		        // check if the front element's frequency of the queue is greater than 1.
		        while(!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
		        
		        if(q.empty()) ans += '#';
		        else ans += q.front();
		        
		    }
		    
		    return ans;
		    
		}

};

// 2
// O(26 * n)
// O(2*26)
class Solution {
	public:
        
		string FirstNonRepeating(string A){
		    
		    vector<int> freq(26, 0); // to store the frequencies.

            // we need to keep the track that which character came first.
		    vector<int> ind(26, 0); // to store the index of the character.
		    
		    string ans = "";
		    
		    for(int i = 0; i < A.size(); i ++){
		        
		        freq[A[i] - 'a']++; // increase the frequency.
		        ind[A[i]- 'a'] = i; // store the index.
		        
		        int index = INT_MAX;
		        
		        for(int i = 0; i < 26; i++){
		           
		            // if the frequency is one then only find the index which is closest to the starting.
		            if(freq[i] == 1 ){
		                index = min(index, ind[i]);
		            }
		        }
		        
		        // did not found any character with frequency == 1.
		        if(index == INT_MAX) ans += '#';
		        
		        // add the character to the answer.
		        else ans += A[index];
		    }
		    
		    return ans;
		   
		}

};