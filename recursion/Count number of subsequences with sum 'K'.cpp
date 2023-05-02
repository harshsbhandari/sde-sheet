#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

int countSubsequenceWithSumK(int ind, int n, vector<int>arr, int reqSum, int currSum){
    
    if(ind == n){
        if(currSum == reqSum)
            return 1;
        else
            return 0;
    }
    
    // pick
    currSum += arr[ind];
    int l = countSubsequenceWithSumK(ind+1, n, arr, reqSum, currSum);

    // not pick
    currSum -= arr[ind];
    int r = countSubsequenceWithSumK(ind+1, n, arr, reqSum, currSum);
       
    return l+r;
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
    
    cout<<countSubsequenceWithSumK(0, n, arr, reqSum, currSum);

    return 0;
}

