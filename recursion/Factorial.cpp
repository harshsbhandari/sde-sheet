#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

int factorial(int i, int& ans){
    if(i == 1)
        return 1;
   
    return i*factorial(i-1, ans);
}

int32_t main(){
    fast;
    
    int n, ans = 1;
    cin>>n;
    
    cout<<factorial(n, ans);
    
    return 0;
}

