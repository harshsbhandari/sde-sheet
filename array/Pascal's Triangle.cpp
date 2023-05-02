vector<vector<int>> generate(int n) {
    vector<vector<int>>ans(n);

    for(int i = 0; i < n; i++){
        // Har iteration par is particular array ka size change karna h like - 1, 2, 3, 4, ...
        ans[i].resize(i+1);
        // First aur last element 1 rahenge hamesha
        ans[i][0] = ans[i][i] = 1;

        // niche wali row upper wali row k adjacent elements ka sum h
        for(int j = 1; j < i; j++)
            ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
    }

    return ans;
}