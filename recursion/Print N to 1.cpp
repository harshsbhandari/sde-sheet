#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

void print(int ind, int n){
    if(ind <= 0)
        return;
    
    cout<<ind<<endl;
    
    print(ind-1, n);
}

int32_t main(){
    fast;
    
    int n; 
    cin>>n;
    
    print(n, n);
    
    return 0;
}

