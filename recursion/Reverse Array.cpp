#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

void reverseArray(vector<int>& arr, int start, int end){
    if(start >= end)
        return ;
        
    swap(arr[start], arr[end]); 
    
    reverseArray(arr, start+1, end-1);    
}

int32_t main(){
    fast;
    
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
        
    reverseArray(arr, 0, n-1);
    
    // Reversed array
    for(auto i : arr)
        cout<<i<<" ";
	
    return 0;
}

