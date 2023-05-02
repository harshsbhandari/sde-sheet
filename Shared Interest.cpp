#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

// I/P -
// 4 5
// 1 1 2 2 2
// 2 2 3 3 4
// 2 3 1 3 4

int32_t main(){
    fast;
    
    int n, m;
    cin>>n>>m;
    
    vector<int>ff(m), ft(m), fw(m);
    for(int i = 0; i < m; i++)
        cin>>ff[i];
        
    for(int i = 0; i < m; i++)
        cin>>ft[i];
        
    for(int i = 0; i < m; i++)
        cin>>fw[i];
        
    map<pair<int,int>,int>mpExist, mpNew;
    
    for(int i = 0; i < m; i++)
        mpExist[{ff[i], ft[i]}]++;
        
    for(int i = 0; i < m-1; i++){
        int x = fw[i];
        
        for(int j = i+1; j < m; j++){
            if(fw[j] == x){
                
                if((mpExist.find({ff[i], ft[j]}) == mpExist.end()) && 
                    (ff[i] != ft[j])){
                    mpNew[{ff[i], ft[j]}]++;
                    mpExist[{ff[i], ft[j]}]++;
                }
                
                if((mpExist.find({ff[j], ft[i]}) == mpExist.end()) && 
                    (ff[j] != ft[i])){
                    mpNew[{ff[j], ft[i]}]++;
                    mpExist[{ff[j], ft[i]}]++;
                }
            }
        }
    }
    
    int countMax = 0, ans = 1;
    
    for(auto i : mpExist){
        int a = i.first.first;
        int b = i.first.second;
        
        if(countMax <= i.second){
            countMax = i.second;
            
            if(ans < (a*b))
                ans = a*b;
        }
    }
        
    cout<<ans;
	
    return 0;
}

