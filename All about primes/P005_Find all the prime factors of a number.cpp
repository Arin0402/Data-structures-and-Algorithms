#include <bits/stdc++.h>
using namespace std;

// we have to print all the prime factors of a number
// ex - 360 = 2 2 2 3 3 5

// 1
// TC - O(n) (worst case) (when n is a prime numebr , for ex - 17, the loop will run 17 times)
// using simple for loops
// start from 2 till n
// psedudo code
    
//  for(i = 2  to i <= N ){

//        while(n%i == 0){

//            print(i);
//          N = N/i;
//      }
//  }

// 2
// TC - O(sqrt(n))
// the above for loop can be run from i = 2 to i*i <= N
// this reduces the time complexity
class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    
	    vector<int> ans;
	    
	    for(int i = 2; i*i <= N; i++){
	        
	        int count = 0;
	        
	        while(N%i == 0){
	            
	            count++;
	            N /= i;
	        }
	        
	        if(count > 0) ans.push_back(i);
	    }
	    
        // try for test case 36 and 17.
	    if(N > 1) ans.push_back(N);
	    
	    return ans;
	    
	}
};


// 3
// TC - O(n log(log n))(creating sieve)  + Log(n)(for finding the factors)
// best approach when the queries are given
// using sieve
// using the concept of least prime factor(P004) mark all the elements till N with their least prime factor
// now we have our array/sieve ready
// start from N and keep dividing untill the N is equal to 1

class Solution{
public:
    void printfctors(int N){
        
        // array of the elements
        int arr[N + 1];
        for(int i = 0; i < N + 1; i++) arr[i] = i;
        
        // sieve
        bool sieve[N + 1];
        for(int i = 0; i < N + 1; i++) sieve[i] = false;
        
        for(int i = 2; i*i <= N; i++){
            
            // unmarked
            if(sieve[i] == false){
                
                int j = i*i;
                while(j <= N){
                    
                    // unmarked
                    if(sieve[j] == false){
                       sieve[j] = true;
                       
                       // as arr[j] is first time divisible by i, so i
                       // will be it's least prime factor.
                       // update it with i.
                       arr[j] = i;
                    }
                    
                    j += i;
                }
            }
        }
        

        // O(logn)                
        
        while( N != 1 ){
            
            cout<< arr[N]<<" ";
            N /= arr[N];
            
        }                
        
    }
};