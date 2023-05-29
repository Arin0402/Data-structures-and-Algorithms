#include <bits/stdc++.h>
using namespace std;

// same as previous.
// Given an array of integers, along with Q queries with two integers X and Y. find out the last occurrence of element X before or at index Y.

#define ll long long int


int main(){

    // input
    ll n; cin>>n;
    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++) cin>>arr[i];

    // map
    map<ll,vector<ll>> occ;
    for(ll i=0;i<n;i++){
        occ[arr[i]].push_back(i);
    }  

    // queries
    ll q; cin>>q;
    while(q--){

        ll x, y; cin>>x>>y;

        // binary search
        ll lo = 0, hi = ((ll)occ[x].size())-1;

        ll ans = -1;
        while(lo <= hi){

            ll mid = (lo+hi)/2;

            if(occ[x][mid]>y){
                hi = mid-1;
            }
            else{
                // possible answer
                ans = occ[x][mid];
                lo = mid+1;
            }
        }

        cout<<ans<<endl;
    }
}