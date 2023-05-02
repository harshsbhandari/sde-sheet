void fun(int ind, vector<int>& arr, vector<int>& ans, int sum){
    // Base case when 'ind' exceeds size of array, add that 'sum' to final answer
    if(ind >= arr.size()){
        ans.push_back(sum);
        return ;
    }
    // Pick
    fun(ind+1, arr, ans, sum+arr[ind]);
    
    // Not pick
    fun(ind+1, arr, ans, sum);
}
vector<int> subsetSums(vector<int> arr, int n){
    vector<int>ans;
    int sum = 0;
    
    fun(0, arr, ans, 0);
    
    return ans;
}
};