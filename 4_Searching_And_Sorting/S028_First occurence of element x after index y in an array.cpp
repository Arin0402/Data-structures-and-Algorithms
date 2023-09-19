#include <bits/stdc++.h>
using namespace std;

// we are given an array containing elements
// we are given an element x
// we have to find the first occurence of x after index y.
// for ex: x = 2, y = 3
// so find the first occurence of 2 after the index 3

// 1
// brute
// iterate

// 2
// create a map<int, vector<int>> mp
// this will store the index of each element in the vector

// then for example we have to find for element 2, so we will apply binary search in that vector of 2 ( 2 -> { indices } )
#define ll long long int

int main(){
    
    // input
    ll n; cin>>n;
    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++) cin>>arr[i];

    // int -> vector<int> (indices of occurence)
    map<ll,vector<ll>> occ;
    for(ll i=0;i<n;i++){
        occ[arr[i]].push_back(i);
    }  

    // Q queries
    ll q; cin>>q;
    while(q--){

        // l and r
        ll x, y; cin>>x>>y;

        // low and high
        ll lo = 0, hi = ((ll)occ[x].size())-1;

        ll ans = -1;

        // binary search
        while(lo <= hi){

            ll mid = (lo + hi)/2; 

            if(occ[x][mid] < y){  
                lo = mid+1;
            }
            else{
                // possible answer
                ans = occ[x][mid];
                hi = mid-1;
            }
        }
        
        cout<<ans<<endl;
    }
}