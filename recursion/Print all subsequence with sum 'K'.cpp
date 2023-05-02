#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

void printSubsequenceWithSumK(int ind, int n, vector<int>arr, vector<int>& ds, int reqSum, int currSum){
    
    if(ind == n){
        if(currSum == reqSum){
            for(auto i : ds)
                cout<<i<<" ";
            
            cout<<endl;
        }
        return ;
    }
    
    ds.push_back(arr[ind]);
    currSum += arr[ind];
    printSubsequenceWithSumK(ind+1, n, arr, ds, reqSum, currSum);
    
    
    ds.pop_back();
    currSum -= arr[ind];
    printSubsequenceWithSumK(ind+1, n, arr, ds, reqSum, currSum);
    
}

int32_t main(){
    fast;
    
    int n, reqSum; 
    cin>>n;
    
    cin>>reqSum;
    
    vector<int>arr(n), ds;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
        
    int currSum = 0;
    
    printSubsequenceWithSumK(0, n, arr, ds, reqSum, currSum);
    
    return 0;
}

