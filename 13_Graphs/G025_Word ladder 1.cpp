#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder

class Solution {
    public:

    // TC - N(no. of words) * M(wordsize) * 26;
    
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        queue<pair<string, int >> q; // to store the word and the steps.
        
        q.push({startWord, 1}); // push the starting word.
        
        unordered_set<string> s(wordList.begin() , wordList.end()); // push all the words in the set. This will help in checking.
        
        s.erase(startWord); // remove the initial word form set. No need to check for the same word again.
        
        // TC - N(no. of words)
        while(!q.empty()){
            
            string word = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(word == targetWord) return steps; // if we get the desired word, return the steps.
            
            // TC - M(wordsize) * 26;
            for(int i =0; i < word.size(); i++ ){ // iterate for each letter in word.
                
                char original = word[i]; // store the original letter
                
                for(char c = 'a' ; c <= 'z'; c++){ // try with each alphabet .
                    
                    word[i] = c; // update the word.
                     
                    if(s.find(word) != s.end()){ // if the word exists in the set.
                        s.erase(word); // remove it.
                        q.push({word, steps+1}); // and push it into the queue.
                    }
                }
                
                word[i] = original; // replace the original letter.
            }
            
        }
        
        return 0;
        
        
    }
};
