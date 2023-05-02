#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

void printNTimes(int ind, int n, string s){
    if(ind >= n)
        return;
    
    cout<<s<<endl;
    
    printNTimes(ind+1, n, s);
    
}

int32_t main(){
    fast;
    
    string s = "A";
    int n; 
    
    cin>>n;
    
    printNTimes(0, n, s);
    
    return 0;
}
