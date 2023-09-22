#include <bits/stdc++.h>
using namespace std;

// IMP
// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();        
        if(n == 1) return 1;

        int master = 0;
        int temp = 0;

        int count = 0;

        while(temp < n){

            while(temp < n && chars[temp] == chars[master]){
                count++;
                temp++;                
            }
            
            if(temp == n) break;

            if(count > 1){
                
                master++;                
                if(count < 9){
                    chars[master] = count + '0';
                    master++;
                }                    
                else{
                    
                    string val = to_string(count);                    
                    for(auto c : val){
                        chars[master] = c;
                        master++;
                    }
                }                                

            }
            else {
                master++;                                
            }

            chars[master] = chars[temp];
            count = 0;

        }

        // for last window
        if(count > 1){                
            master++;                
            
            if(count < 9)
                chars[master] = count + '0';
            else{
                
                string val = to_string(count);                    
                for(auto c : val){
                    chars[master] = c;
                    master++;
                }

                master--;
            }
        }

        return master + 1;


    }
};