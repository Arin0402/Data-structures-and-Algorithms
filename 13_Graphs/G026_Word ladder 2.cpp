#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
class Solution {
    public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s(wordList.begin(), wordList.end()); // to store the strings for checking. 
        
        queue<vector<string>> q; // queue to store vector of strings.
        q.push({beginWord}); // push the starting word.
        
        vector<string> usedOnLevel; // store the new words created on a level. We will delete these words after the level is completed.
        usedOnLevel.push_back(beginWord); // push the starting word.
        
        vector<vector<string>> ans;
        int level =0 ;
        
        while(!q.empty()){
            
            vector<string> vec = q.front();
            q.pop();
            
            // for the first time , only beginWord will be there, so size will be 1 and level will be 0.
            if(vec.size() > level){ 
                
                level++; // increase the level.
                for(auto it : usedOnLevel ){ // remove all the words in usedOnLevel.
                    s.erase(it);
                    
                }
            }
            
            string word = vec.back(); // get the last word of the vector.
            
            if(word == endWord){ // got desired word.
                
                if(ans.size() == 0){ // ans is empty.
                    ans.push_back(vec);
                }
                // ans is not empty, so compare the sizes. if the size of vec is same as that in answer, then only push it.
                else if(ans[0].size() == vec.size()) ans.push_back(vec);
                // size of vec is greater, so break as we need only smallest paths.
                else break;
            }
            
            for(int i = 0 ; i < word.size(); i++){
                
                char ori = word[i];
                
                for(char c = 'a' ; c <= 'z' ; c++){
                    
                    word[i] = c;
                    
                    if(s.find(word) != s.end()){
                        
                        vec.push_back(word); // insert word in vec.
                        q.push(vec); // puah vec in queue.
                        
                        usedOnLevel.push_back(word); // insert new word in usedOnLevel.
                        vec.pop_back(); // remove the last word of vec to try other words also.
                                            
                    }
                }
                
                word[i] = ori;
            }
                        
        }
        
        return ans;
        
    }
};