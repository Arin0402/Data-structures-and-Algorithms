#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1294/C

// we have been given a number n
// we have to find three factors of this number such that a != b != c != 1
// we will use greedy approach here
// we will assign a as the smallest factor
// then b and the c

// 1

vector<int> helper(int n){
    
    vector<int> ans;
    
    // initialise three factors
    int a = 1, b = 1, c = 1;
        
    // find the first factor a
    for(int i = 2; i <= sqrt(n); i++){
        
        // can divide.
        if(n%i == 0){
            a = i;
            break;
        }
    }
    
    // not possible. No factor found
    if(a == 1){
        ans.push_back(-1);
        return ans;
    }   
    
    // divide it by a
    n = n/a;

    // find b 
    for(int i = 2; i <= sqrt(n); i++){
        
        // can divide
        if(n%i == 0){

            // i should not be equal to a
            // n/i shouls not be equal to i (i.e 4x4 = 16 , this is not allowed)
            // n/i should not be equal to a (i.e c != a )
            if(i != a && (n/i != i) && (n/i != a)){                
                b = i;      
                break;
            }
        }
        
    }
    
    // not possible
    if(b == 1){
        ans.push_back(-1);
        return ans;
    }   
    
    // third factor    
    c = n/b;
    
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(c);
    
    return ans;
}

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        
        vector<int> ans = helper(n);
        
        // not possible
        if(ans[0] == -1) cout<<"NO"<<endl;
        else {
            
            cout<<"YES"<<endl;

            // print the factors
            for(auto ele : ans) cout<<ele<<" ";
            cout<<endl;
        }
        
    }
}
