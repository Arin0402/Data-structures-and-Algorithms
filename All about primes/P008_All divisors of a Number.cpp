#include <bits/stdc++.h>
using namespace std;

// 1
// o(n)
// run for loop and print divisors

// 2
// O(sqrt(n))
// O(sqrt(n))
class Solution {
  public:
    void print_divisors(int n) {
        
        // store the other pair of division
        // for ex 4*5 = 20, so it will store 5
        // as we have to print the factors in ascending order
        vector<int> second;    
        
        for(int i = 1; i*i <= n; i++ ){
            
            // divides
            if(n%i == 0){
                
                // print the first element of the pair
                cout<<i<<" ";
                
                // second element of thr pair
                if( n/i != i)
                    second.push_back(n/i);
            }
        }
        
        // print it in the reverse order
        for(int i = second.size() - 1; i >= 0; i--) cout<<second[i]<<" ";
    }
};