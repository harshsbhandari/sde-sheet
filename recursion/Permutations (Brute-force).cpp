void permutations(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, map<int,int>mp){
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return ;
    }

    for(int i = 0; i < arr.size(); i++){
        // If element is not found in 'map' than we can insert it because it is available
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = 1;
            ds.push_back(arr[i]);
            permutations(arr, ans, ds, mp);
            
            // After the recursion call is over we mark this element as available again
            mp.erase(arr[i]);
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& arr) {
    vector<vector<int>>ans;
    int n = arr.size();
    vector<int>ds;
    map<int,int>mp;

    permutations(arr, ans, ds, mp);

    return ans;
}