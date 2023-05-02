void fun(int ind, vector<vector<int>>& ans, vector<int>& arr, vector<int>& ds){
    ans.push_back(ds);

    for(int i = ind; i < arr.size(); i++){
        // Making sure that we do not take duplicates for the same position
        // (i != ind) ie: It second, third or, ...... time
        if(i != ind && arr[i] == arr[i-1])
            continue;
        
        // Pick
        ds.push_back(arr[i]);
        fun(i+1, ans, arr, ds);

        // Not pick
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    vector<vector<int>>ans;
    int n = arr.size();
    vector<int>ds;
    // To make all duplicates come next to each others
    sort(arr.begin(), arr.end());

    fun(0, ans, arr, ds);

    return ans;
}