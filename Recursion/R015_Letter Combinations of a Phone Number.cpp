#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

// using recursion
// Time Complexity: O((4^N).N), as each digit can map string of maximum length as 4, so there can be 4^N combinations possible for N digit number. Each combination takes O(N) complexity to form.

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void helper(int ind, string &s, vector<string> &pattern, int a[], int N, vector<string> &ans){
        
        // got the pattern of size N.
        if(ind == N){
            ans.push_back(s);
            return;
        }
        
        // number to be pressed
        int num = a[ind]; 
        
        // string for that number
        string temp = pattern[num];
        
        // for every character of that string
        for(int i = 0; i < temp.size(); i++){
            s.push_back(temp[i]);
            helper(ind + 1, s, pattern, a, N, ans);
            s.pop_back();
        }
        
        
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> pattern = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                    "pqrs", "tuv", "wxyz"
        };
        
        
        vector<string> ans;
        string s = "";
        
        helper(0, s, pattern, a, N, ans);
        
        return ans;
        
    }
};

// 2
// using for loops
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
    vector<string> pad = { // pad.
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    // Dry run.
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) return {};
        
        vector<string> result;
        result.push_back("");
                
        for(auto d: digits ){
            
            vector<string> tmp;
            for(auto s: pad[d -'0']){                                
                
                for(auto t : result){
                    
                    tmp.push_back(t + s);
                }
                
            }
            
            result = tmp;
        }
        
        return result;
        
    }
};
