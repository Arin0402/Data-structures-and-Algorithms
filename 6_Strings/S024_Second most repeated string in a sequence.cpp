#include <bits/stdc++.h>
using namespace std;

// 1
// TC - O(n)
// SC - O(N)

class Solution
{
  public:
  
    string secFrequent (string arr[], int n)
    {
        
        // store the frequencies.
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; i++ ){
            mp[arr[i]]++;
            
        }
        
        string prev = ""; // second largest frequency.
        string curr = ""; // largest frequency.
        
        int ansPrev = INT_MIN; // second largest frequency.
        int ansCurr = INT_MIN; // largest frequency.
        
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            
            string str = itr->first;
            int num = itr->second;
            
            // found frequency greater than largest freq.
            if(num > ansCurr){
                ansPrev = ansCurr; // assign this to second largest.
                prev = curr;
                
                ansCurr = num; // update.
                curr = str;
            }
            // frequency is greater than second largest freq.
            else if( num > ansPrev ){
                
                ansPrev = num; // update.
                prev = str;
            }
            
        }
        
        return prev;
        
    }
    
};