#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

// 1
// naive
// O(N^2)

// 2
// same as before (S051)
// we will count the substrings with at most k different characters
// then we will count the substrings with at most k - 1 different characters
// answer will be count(s, k) - count(s, k-1);
// !---------------------------NOTE-------------------!
// if the code gives tle then, it is because we are calculating the size of the map many time
// so instead of a map,  keep a variable to track the unique characters and a frequency array of size 26 to keep track of frequency
class Solution
{
  public:
  
    long long int helper(string s, int k){
        
        int n = s.size();
        
        // pointers
        int l = 0;
        int r = 0;
        
        long long int count = 0;
        
        // to store th frequencies
        unordered_map<char, int> mp;
        
        while(r < n){
            
            // increase the frequency
            mp[s[r]]++;
            
            // map size <= k
            if(mp.size() <= k){
                
                // add all the substrings into the count
                // for ex - abaa will have abaa, baa, aa, a as the substrings
                count += r - l + 1;
            }
            // size greater
            else {
                
                while(mp.size() > k){
                    
                    // decrease the frequency
                    mp[s[l]]--;
                    
                    // remove from the map if frequency is zero
                    if(mp[s[l]] == 0) mp.erase(s[l]);
                    
                    // move
                    l++;
                }
                
                // for the rth character that was added
                count += r - l + 1;
            }
            
            // move
            r++;
        }
        
        return count;
        
    }
    long long int substrCount (string s, int k) {
    	
    	
    	return helper(s, k) - helper(s, k - 1);
    }
};