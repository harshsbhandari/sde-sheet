#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

// Is function se ye pata chal raha h, aage se fast pahuche ya piche se
int fun(char c, map<char, int>mp){
    // a - 'aage' se
    // b - 'piche' se
    int a = mp[c], b = (26-mp[c]);
    
    return min(a, b);
}

int32_t main(){
    fast;
    
    string s;
    cin>>s;
    
    int n = s.length();
    map<char, int>mp;
    int count = 0;
    
    for(char i = 'A'; i <= 'Z'; i++){
        mp[i] = count;
        count++;
    }
    
    int ans = fun(s[0], mp);
    
    for(int i = 0; i < n-1; i++){
        char a = s[i], b = s[i+1];
        int temp1 = mp[a], temp2 = mp[b];
        
        int ans1 = abs(temp1-temp2);
        int ans2 = fun(a, mp)+fun(b, mp);
        
        ans += min(ans1, ans2);
    }
    
	cout<<ans;
	
    return 0;
}

