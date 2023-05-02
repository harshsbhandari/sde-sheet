void rotate(vector<vector<int>>& arr) {
    int n = arr.size();

    // transpose of matrix - row ko col, col ko row, me convert karna
    // 1 2 3 
    // 4 5 6
    // 7 8 9
    // to
    // 1 4 7
    // 2 5 8
    // 3 6 9
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            swap(arr[i][j], arr[j][i]);
    }

    // sari rows ko reverse kar dia
    for(int i = 0; i < n; i++)
        reverse(arr[i].begin(), arr[i].end());
}