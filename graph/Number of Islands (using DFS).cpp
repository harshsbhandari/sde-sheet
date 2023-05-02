// Number of connected components count karne h grid me bas aur kuch nahi

// Check whether 'newr' and 'newc' coordinates satisfy these conditions -
// (0 <= newr < n) && (0 <= newc < m)
// not visited
// exists land(value == 1) at that coordinate
bool check(int newr, int newc, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid){
    if(newr >= 0 && newr < n && newc >= 0 && newc < m && 
        !vis[newr][newc] && grid[newr][newc] == '1')
        return true;

    return false;
}
void dfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis){
    // DFS me sabse pehle current node ko visited mark kar do 
    vis[x][y] = 1;

    // 'delr' aur 'delc' - 4 directions check karne k liye h, kisi specific coordinate k respect me 
    // (0, 1), (1, 0), (0, -1), (-1, 0)
    int delr[] = {0, 0, 1, -1};
    int delc[] = {1, -1, 0, 0};

    for(int i = 0; i < 4; i++){
        int newr = delr[i]+x;
        int newc = delc[i]+y;

        // check karo new coordiantes k liye, kya ye valid h, agar valid h to is new valid coordinate par DFS call karo
        if(check(newr, newc, n, m, vis, grid))
            dfs(newr, newc, n, m, grid, vis);
    }

}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n, vector<int>(m, 0));
    // Number of island count karta h
    int count = 0;

    // Matrix k har cell par traversal karna h, check karna h ki land exists kar rha h is coordiante par AND ye coordinate visited nahi h
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                dfs(i, j, n, m, grid, vis);
                count++;
            }
        }
    }

    return count;
}