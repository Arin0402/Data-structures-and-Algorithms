#include <bits/stdc++.h>
using namespace std;

// IMP
// https://leetcode.com/problems/string-compression/description/


class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0; // left pointer
        int j = 0; // right pointer
        int ind = 0; // index at which we have to update.
        int n = chars.size();

        while( j <= n){
            // character same.
            if(j < n && chars[i] == chars[j]) j++;
            else {

                int count = j-i; // count of characters                                 
                ind++; // increase the updation index.                

                // Two cases.
                if(count > 1 && count <= 9){

                    // update the index
                    chars[ind] = count + '0';                  
                    ind++; // move to next index.
                }
                else if(count > 9 ){                    
                    
                    // convert the count into string and then update.
                    string val = to_string(count);                    
                    for(auto c : val){
                        chars[ind] = c;
                        ind++;
                    }
                }

                // make i and j equal so that we can start for new alphabet.
                i = j; 

                // j out of bound.
                if(j == n) break;

                // for case ["a","a","a","b","b","a","a"]
                if(ind < i){
                    chars[ind] = chars[i];
                }
                
            }
        }        

        return ind;
    }
};