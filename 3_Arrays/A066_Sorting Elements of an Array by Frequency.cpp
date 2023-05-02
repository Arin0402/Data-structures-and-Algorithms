#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

// comparator function for sort 
bool cmp(pair<int,int>&a,pair<int,int>&b){
    
    // frequency is not same
    if(a.first!=b.first){
        return a.first > b.first;
    }
    // frequency is same, smaller number first.
    else{
        return a.second < b.second;
    }
}

vector<int>solve(int arr[],int n){
    
    unordered_map<int,int>um;
    
    // add the frequencies
    for(int i=0;i<n;i++){
        um[arr[i]]++;
    }
    
    // to store the pairs
    vector<pair<int,int>>vp;
    
    // iterate the map
    for(auto i:um){
        vp.push_back({i.second,i.first});
    }
    
    
    vector<int> ans;
    
    // sort the vp.
    sort(vp.begin(),vp.end(), cmp);
    
    // build the ans vector.
    for(int i=0;i<vp.size();i++){
        int j;
        for(j=0;j<vp[i].first;j++){
            ans.push_back(vp[i].second);
        }
    }
    
    
    return ans;
}
int main() {
    
    // all the input and printing work    
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        vector<int>v=solve(arr,n);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}