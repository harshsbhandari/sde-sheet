void findCombinations(int ind, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds){
    // If target is reached, that's our answer, return
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i = ind; i < arr.size(); i++){
        // if consecutive elements are same
        if((i > ind) && (arr[i] == arr[i-1]))
            continue;
        
        if(arr[i] > target)
            break;

        // Pick
        ds.push_back(arr[i]);
        findCombinations(i+1, arr, target-arr[i], ans, ds);

        // Not pick
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    vector<int>ds;
    vector<vector<int>>ans;
    // So that all of the similar elements come together in the array
    sort(arr.begin(), arr.end());

    findCombinations(0, arr, target, ans, ds);
    
    return ans;
}