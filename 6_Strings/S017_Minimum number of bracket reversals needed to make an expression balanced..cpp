#include <bits/stdc++.h>
using namespace std;

// 1
// using extra space.
// TC - O(n)
// SC - O(n)

int countRev (string s)
{   
    // idea is to get the number of Close and Open unclosed braces first.
    // the pairs braces would cancel themselves so no need to count.
    // then proceed further.
    
    // to store characters.
    stack<char> st;
    
    int cntClose = 0; // number of Close braces ( '}') left.
    
    for(int i =0 ; i < s.size(); i++){
        
        if(s[i] == '}'){
            
            if(st.empty()) cntClose++;
            else st.pop(); // got pair.
        }
        else {
            st.push('{');
        }
    }
    
    int  cntOpen = st.size();  // (' { ') // number of open breaces left.
    
    int ans = 0;
    
    // It would require one operation to get a pair from same type of braces.
    // ex - {{{{ => {{{} , so one operation.
    
    // It would require two operation to get a pair from different type of braces.
    // ex - } { => { } , so two operation.
    
    
    ans += cntOpen/2; 
    ans += cntClose/2;
    
    cntOpen = cntOpen%2;
    cntClose = cntClose%2;
    
    if(cntOpen != cntClose) return -1; // remainig are not same, not possible.
    
    // for different type of braces.
    else ans += cntOpen*2;
    
    return ans;
}

// 2
// using constant space 
// O(n);
// O(1);

int countRev (string s)
{   
     
    int cntOpen = 0; // count the number of open bracket left.
    int cntClose = 0; // count the number of close braces left.
    
    for(int i =0 ; i < s.size(); i++){
        
        if(s[i] == '}'){
            
            if(cntOpen == 0) cntClose++; // no open bracket.
            else cntOpen--; // got pair.
        }
        else {
            cntOpen++;
        }
    }
    
    
    int ans = 0;
    
    ans += cntOpen/2; 
    ans += cntClose/2;
    
    cntOpen = cntOpen%2;
    cntClose = cntClose%2;
    
    if(cntOpen != cntClose) return -1; // remainig are not same, not possible.
    
    // for different type of braces.
    else ans += cntOpen*2;
    
    return ans;
    
    
}
