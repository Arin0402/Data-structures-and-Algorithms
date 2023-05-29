#include <bits/stdc++.h>
using namespace std;

// We have been given an array denoting the strengths of the worker.
// the array contains odd number of workers(elements)

// we have to make pairs of workers such that the total cost of all the pairs is minimum
// cost is defined by the absolute difference of the strengths in a pair

// whenever such types of question come where we have to remove one element, then focus should be on the element 
// that should be removed

// 1
// we cannot sort the array and exclude the largest element
// It will fail in the following test case

    // 1 2 100 150 151


// 2
// brute
// we can try to skip every worker and calculate  for rest of the workers
// we find the minimum cost by doing this
// O(N^2)
#define ll long long int

// to calculate the cost of the workers array of even length
ll findScoreIfEven(vector<ll> &arr){

    sort(arr.begin(), arr.end());

    ll sum = 0;
    for(ll i=1;i<arr.size();i+=2) sum+=(arr[i]-arr[i-1]);

    return sum;
}

int main(){    

    // input part
    ll n; cin>>n;        
    vector<ll> score(n, 0);

    for(ll i=0;i<n;i++) cin>>score[i];

    ll ans = 1e18;

    for(ll nikalneWaleEmployeeKaIndex = 0; nikalneWaleEmployeeKaIndex < n ; nikalneWaleEmployeeKaIndex++ ){

        // create array for the remaining workers
        vector<ll> brr;

        for(ll j = 0 ; j < n ; j++){       
            if(nikalneWaleEmployeeKaIndex == j) continue;
            brr.push_back(score[j]);
        }

        // calculate the score
        ll iskoNikaleKeBaadScore = findScoreIfEven(brr);

        // update the minimum
        ans = min(ans, iskoNikaleKeBaadScore);
    }
    cout<<ans<<endl;
   
}


// 3
// sort the array
// we create two arrays prefix and suffix
// we will compute for the even indexed workers (assume 1 based indexing)
// the odd workers will have the value 0

// for prefix array (even indexed workers)
// we wiil compute the cost if the ith worker makes pair with the (i-1)th worker

// for suffix array (even indexed workers)
// we wiil compute the cost if the ith worker makes pair with the (i+1)th worker

// for ex-   1 3 7 10 12

// prefix -> 0 2 2 5 5
// suffix -> 6 6 2 2 0

// explanation for example in the code

// here prefix array denotes the minimumcost from index 0 till the ith index
// here suffix array denotes the minimumcost from index i till the last index

// we will try skipping each worker and find the minimum cost for rest of the workers.
// 1 based indexing

#define ll long long int

int main(){
    
    // input part
    ll n; cin>>n;
    vector<ll> arr(n+2, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    // sort the array
    sort(arr.begin()+1, arr.end()-1);

    // create two arrays
    vector<ll> pref(n+2, 0), suff(n+2, 0);

    for(ll i = 1; i <= n; i++){
        // odd
        // index is odd, then copy the previous value
        if(i%2) pref[i] = pref[i-1];
        // even
        // else compute the value for ith ans (i-1)th
        else pref[i] = pref[i-1] + (arr[i]-arr[i-1]);
    }

    for(ll i = n; i >= 1; i--){

        if(i%2) suff[i]=suff[i+1];        
        else suff[i] = suff[i+1] + arr[i+1] - arr[i];
    }

    // for ex-   1 3 7 10 12

    // prefix -> 0 2 2 5 5
    // suffix -> 6 6 2 2 0

    // initialise answer
    ll ans = 1e18;

    for(ll i = 1; i <=n; i++){

        ll left = i;

        // odd index worker
        // that means there are even number of eworkers on both the side so pairs can be made easily
        if(left%2){
            ans = min(ans, pref[i-1]+suff[i+1]);            
        }
        // even index
        // that means there are odd number of elements on both the side so pair would be made and one-one element
        // would be left on both the sides       
        // calculate for that reamainig elements seperately
        else{
            ans = min(ans, pref[i-1] + suff[i+1] + (arr[i+1] - arr[i-1]));
        }
    }

    cout<<ans<<endl;
}