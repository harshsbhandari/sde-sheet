#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

// Prefix sum type ka question h, 2 '|' k bich me jitne star('*') aa rahe h, bas unko ji count karna h 

int32_t main(){
    fast;
    
    string s;
    cin>>s;
    
    int n = s.length(), ind;
    vector<int>arr(n);
    
    // Ye first '|' tak 'ind' le aayega, aur usse pehle vale indexes par arr[i] = 0 kar dega
    for(int i = 0; i < n; i++){
        arr[i] = 0;
        
        if(s[i] == '|'){
            ind = i;
            break;
        }
    }
    
    int count = 0, val = 0;
    
    for(int i = ind; i < n; i++){
        if(s[i] == '*'){
            count++;
            arr[i] = val;
        }
        
        if(s[i] == '|'){
            val = count;
            arr[i] = val;
        }
    }

    // s = |**|*|*
    // arr = 0002233
    
    // Ye hai answer
    // cout<<(arr[endIndex-1]-arr[startIndex-1])
    
    return 0;
}

