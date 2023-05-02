#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

void print(int ind, int n){
    if(ind > n)
        return;
    
    print(ind+1, n);
    
    // 'print' statement is after the recursion call ie: backtracking
    cout<<ind<<endl;
}

int32_t main(){
    fast;
    
    int n; 
    cin>>n;
    
    print(1, n);
    
    return 0;
}

