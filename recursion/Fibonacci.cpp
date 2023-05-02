#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

int fibonacci(int n){
    if(n <= 1)
        return n;
    
    int first = fibonacci(n-1);
    int second = fibonacci(n-2);
    
    return first+second;
}

int32_t main(){
    fast;
    
    int n;
    cin>>n;
    
    cout<<fibonacci(n);
    
    return 0;
}

