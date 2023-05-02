void permutations(int ind, vector<int>& arr, vector<vector<int>>& ans){
    // Base case
    if(ind == arr.size()){
        ans.push_back(arr);
        return ;
    }

    for(int i = ind; i < arr.size(); i++){
        // Swapping the elements
        swap(arr[i], arr[ind]);
        permutations(ind+1, arr, ans, ds);

        // Resuming to normal condition
        swap(arr[i], arr[ind]);
    }
}
vector<vector<int>> permute(vector<int>& arr) {
    vector<vector<int>>ans;
    int n = arr.size();

    permutations(0, arr, ans, ds);

    return ans;
}