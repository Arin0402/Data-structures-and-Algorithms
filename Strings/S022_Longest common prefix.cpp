#include <bits/stdc++.h>
using namespace std;

// 1
// vertical scanning.
// TC -O(m*n)
// Sc- O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        
        int n = strs.size();
        
        // size of the first string.
        for(int i = 0 ;  i < strs[0].size(); i++ ){
                
            bool matched = true;

            // compare with the rest of the strings.            
            for(int j = 1 ; j <n ; j++ ){
                
                // prefix did not match.
                if(strs[j].substr(0, i+1) != strs[0].substr(0, i+1)){
                    return ans;
                }                
            }
            
            // prefix matched with all the strings.
            ans = strs[0].substr(0, i+1);
        }
        
        return ans;
                    
    }
};

// 2
// using trie.
// TC - O(m*n)
// Sc - O(m*n);
// Bulding trie is time consuming but after building , finding lcp takes only O(m) time. ( m - length of longest common prefix).