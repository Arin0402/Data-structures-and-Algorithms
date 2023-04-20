#include <bits/stdc++.h>
using namespace std;

// https://www.codechef.com/problems/LARGESTY?tab=statement
// watch the codechef video soluion for explanation 


int main() {
	
	// number of test cases
	int t;
	cin>>t;
	
	while(t--){
	    
        // take the input
	    int n, x;
	    cin>>n>>x;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++) cin>>arr[i];
	    

        // answer
	    int res = 0;
	    
        // we will start from the lowest bit, as we wnat our answer to be maximum
	    for(int i = 0; i < 30; i++){
	        
	        // count of the numbers which have different set bits at the ith bit
	        int cnt = 0;
	        
            // iterate for the numbers
	        for(int j = 0; j < n; j++){
	            
                // check if set bit or not
	            if(arr[j]&(1<<i)) cnt++;
	        }
	        
	        // either all have set bit or none have set bit, so move on
            // we wnat the numbers which have different bits at the ith bit
	        if(cnt == 0 || cnt == n) continue;
	    
	        // temporary answer
	        int temp = 0;
	        
            // start from the last bit as we wnat our answer to be maximum
	        for(int j = 29; j >= 0; j--){
	            
                // we cannot have a set bit in Y at the position i
	            if(j == i) continue;
	            
	            int tempadd = 1<<j;
	            
                // check if the temp is still less than x or not
	            if(temp + tempadd > x) continue;
	            temp += tempadd;
	        }
	        
            // update the res
	        res = max(res, temp);
	        
	    }
	    
	    cout<<res<<endl;
	    
	}
	
}
