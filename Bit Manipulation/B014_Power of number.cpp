#include <bits/stdc++.h>
using namespace std;

// calculate the power p of number n, 

// 1
// loop
// O(p)

// 2
// Log(p)

int main(){

    int p, n;

    int ans = 1; 

    // while power is greater than 0
    while(p){

        // first bit from the left of p.
        int first_bit = (p&1);

        // if the firstBit is 1
        if(first_bit){
            ans = ans*n;
        }

        n = n*n;

        // right shift the p
        p = p>>1;
    }

    cout<<ans<<endl;

    return 0;
}
