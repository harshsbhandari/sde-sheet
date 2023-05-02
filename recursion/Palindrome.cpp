#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

bool palindrome(string str, int start, int end){     
    if(start > end)
        return true;

    if(str[start] != str[end])
        return false;
    
    return palindrome(str, start+1, end-1);
}

int32_t main(){
    fast;
    
    string str;
    cin>>str;
    
    int start = 0, end = str.length()-1;
    
    if(palindrome(str, start, end))
        cout<<"YES";
    else
        cout<<"NO";
    
    return 0;
}

