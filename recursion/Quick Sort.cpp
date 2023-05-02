#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while(i < j){
        while(arr[i] <= pivot && i <= high-1)
            i++;
        
        while(arr[j] > pivot && j >= low+1)
            j--;
            
        if(i < j)
            swap(arr[i], arr[j]);
    }
    // arr[low] - is the 'pivot', and arr[j] - is smaller than 'pivot'
    swap(arr[low], arr[j]);
    
    return j;
}

void qS(vector<int>& arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        
        qS(arr, low, pivot-1);
        qS(arr, pivot+1, high);
    }
}

int32_t main(){
    fast;
    
    int n; 
    cin>>n;
    
    vector<int>arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
        
    qS(arr, 0, n);
    
    for(auto i : arr)
        cout<<i<<" ";
  
    return 0;
}

