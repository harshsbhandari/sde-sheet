void findCombination(int ind, int target, vector<vector<int>>& ans, vector<int>& arr, 
    vector<int>& ds){
    if(ind == arr.size()){
        if(target == 0)
            ans.push_back(ds);

        return ;
    }

    // pick, that's why that number s deleted from the 'target'
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(ind, target-arr[ind], ans, arr, ds);
        ds.pop_back();
    }

    // not pick, thus nothing deleted from 'target'
    findCombination(ind+1, target, ans, arr, ds);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>>ans;
    vector<int>ds;

    findCombination(0, target, ans, arr, ds);

    return ans;
}