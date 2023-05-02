#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

void printSubsequences(int ind, vector<int>& arr, vector<int>& ds, int n){
    if(ind >= n){
        for(auto i : ds)
            cout<<i<<" ";
        cout<<endl;
        return ;
    }
    
    // add
    ds.push_back(arr[ind]);
    printSubsequences(ind+1, arr, ds, n);
    
    // remove
    ds.pop_back();
    printSubsequences(ind+1, arr, ds, n);
}

int32_t main(){
    fast;
    
    int n;
    cin>>n;
    
    vector<int>arr(n), ds;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    printSubsequences(0, arr, ds, n);
    
    return 0;
}

