#include <bits/stdc++.h>
using namespace std;


// 1
// using recursion
// pick - not pick
// TC - O(2^n)
// SC - O(n)

void helper(int i ,int n, string s, string str, vector<string> &ans ){
     
    if(i >= n){
        if( s != "") ans.push_back(s);
        return;
    }
    
    // pick
    helper(i+1, n, s + str[i], str, ans);
    
    // not pick
    helper(i+1, n, s , str, ans);
}

vector<string> subsequences(string str){		
	
    vector<string> ans;
    int n = str.size();
    
    helper(0, n, "", str, ans );
    
    return ans;
}


// 2
// using power set
// O(2^n * n)

vector<string> subsequences(string str){
	
    int n = str.size();
    vector<string> ans;    
    
    // 2^n
    for(int i =0 ; i < pow(2, n) ; i++){
        
        string s = "";
        
        // n
        for(int j = 0 ; j < n ; j++ ){                
            if(i&(1<<j)) s += str[j];
        }
               
        if(s != "") ans.push_back(s);
    }
	
    return ans;
}
