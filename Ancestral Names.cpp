#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

// BASIC question of handling roman numerals

int romanToInt(string s){
    int n = s.length();
    int ans = 0;
    map<char, int>mp;
    
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    for(int i = 0; i < n-1; i++){
        // If later number is greater than the previous than we subtract the previous number
        if(mp[s[i]] < mp[s[i+1]])
            ans -= mp[s[i]];
        // If later number is smaller than the previous than we add the previous number
        else
            ans += mp[s[i]];
    }
    
    // Handling last one
    ans += mp[s[n-1]];
        
    return ans;   
}

bool mySort(string& a, string& b){
    auto breakpointA = a.find(' ');
    auto breakpointB = b.find(' ');
    
    // 'str1' and 'str2' are without roman numerals
    string str1 = a.substr(0, breakpointA);
    string str2 = a.substr(0, breakpointB);
    
    // only roman numerals
    string x = a.substr(breakpointA + 1);
    string y = b.substr(breakpointB + 1);
    
    // If strings (without roman numerals) are equal that means that we need to consider roman numerals
    if(str1 == str2)
        return romanToInt(y) >= romanToInt(x);
    else
        return b > a;
}

int32_t main(){
    fast;
    
    // int n;
    // cin>>n;
    
    // vector<int>arr(n);
    // for(int i = 0; i < n; i++)
    //     cin>>arr[i];
    
    vector<string>arr =  {
		"Steven XL", "Steven XVI", "David IX", "Mary XV", "Mary XIII", "Mary XX"
	};
	
    sort(arr.begin(), arr.end(), mySort);
        
    // for(auto i : arr)
    //     cout<<i<<endl;
	
    return 0;
}

