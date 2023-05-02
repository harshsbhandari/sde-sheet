#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'


void merge(vector<int>& arr, int low, int mid, int high){
    vector<int>temp;
    
    int left = low;
    int right = mid+1;
    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    
    // assigining in main array
    for(int i = low; i <= high; i++)
        arr[i] = temp[i-low];
}


void mS(vector<int>& arr, int low, int high){
    if(low >= high)
        return ;
    
    int mid = (low+high)/2;
    
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    
    // merge
    merge(arr, low, mid, high);
}

int32_t main(){
    fast;
    
    int n; 
    cin>>n;
    
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
        
    mS(arr, 0, n);
    
    for(auto i : arr)
        cout<<i<<" ";
  
    return 0;
}

