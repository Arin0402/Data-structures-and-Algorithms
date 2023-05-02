#include <bits/stdc++.h>
using namespace std;

// Q. You are given q queries. In each query you are given an integer n. 
//     you have to give the count of numbers for which the given n is smallest prime factor

//     This is an easy question

//     for ex - if n == 2, the count will be 2, 4, 6, 8 10, 12 ... till 10^6.

//     we will use sieve method to solve this problem
//     create a sieve and mark all of them as false 
//     we will start form i =  2  till i*i <= n
//     keep a count of all the numbers that are marked as true by the i.
//     update the ith index of the sieve by this count.
//     by this , for a particular n, we can get the count.

void createSieve(){

    // create sieve
    int sieve[1000001];    
    for(int i =0; i < 1000001; i++) sieve[i] = 0;

    for(int i = 2; i*i <= 1000001; i++){

        // unmarked
        if(sieve[i] == 0){
            
            // initialize with 1 as the i itself will also be counted
            int count = 1; 
            
            int j = i*i;

            while(j <= 1000001){
                
                // unmarked
                if(sieve[j] == 0){
                    count++;
                    sieve[j] = 1;
                }

                j += i;
            }
            
            // update the sieve
            sieve[i] = count;

        }
    }

}
 