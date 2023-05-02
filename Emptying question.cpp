// Given an integer array nums, do the following operations:
// If the first element is the smallest element in the array, remove it
// Otherwise, puts it to the end of the array
// Return number of operations it takes for nums to be empty.
// Example
// Input
// nums:
// [2,1,3]
// Output
// 5

// Explanation
 
// After 1st operation, nums becomes [1, 3, 2] since 2 is not the smallest value in [2,1,3], puts 2 to the end of nums
// After 2nd operation, nums becomes [3, 2] since 1 is the smallest value in [1,3,2]
// After 3rd operation, nums becomes [2,3] since 3 is not the smallest value in [3,2], puts 3 to the end of nums
// After 4th operation, nums becomes [3] since 2 is the smallest value in [2,3]
// After 5th operation, nums becomes [] since 5 is the smallest value in [5]
// After the 5th operation, nums becomes [].
// So return 5.

// Constraints
// 1 <= nums.length <= 2*10^5
// 1 <= nums[i] <= 10^5 where 0 <= i < nums.length

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long 
#define float double
#define endl '\n'

int32_t main(){
    fast;
    
    int n;
    cin>>n;
    
    deque<int>dq;
    multiset<int>st;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        
        dq.push_back(x);
        st.insert(x);
    }
    
    int count = 0;
    
    while(!dq.empty()){
        auto it = dq.front();
        auto minn = st.begin();
        
        if(it == *minn){
            st.erase(minn);
            dq.pop_front();
        }
        else{
            dq.pop_front();
            dq.push_back(it);
        }
        
        count++;
    }
    
    cout<<count;
	
    return 0;
}