#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/power-set4302/1

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    
		    int n = s.size();
		    vector<string> ans;
		    
		    for(int num = 1; num < (1<<n); num++){
		        
		        string temp = "";
		        
		        for(int i = 0; i < n; i++){
		            if(num&(1<<i)) temp += s[i];
		        }
		        
		        ans.push_back(temp);
		    }
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
};