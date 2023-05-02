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

void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& vis){
    queue<pair<int,int>>q;
    int n = grid.size();
    int m = grid[0].size();
    // 'delr' aur 'delc' - 4 directions check karne k liye h, kisi specific coordinate k respect me 
    // (0, 1), (1, 0), (0, -1), (-1, 0)
    int delr[] = {0, 0, 1, -1};
    int delc[] = {1, -1, 0, 0};
    
    // BFS me sabse pehle yahi karna h, current node ko 'queue' me push karo aur 'visited' mark karo
    q.push({x, y});
    vis[x][y] = 1;

    while(!q.empty()){
        auto it = q.front();
        int row = it.first;
        int col = it.second;
        q.pop();

        // current node k 4 directions me check karo, kya koi unvisited node h, jo 1 h, agar h to 'queue' me push karo aur 'visited' mark karo
        for(int i = 0; i < 4; i++){
            int newr = delr[i]+row;
            int newc = delc[i]+col;

            if(check(newr, newc, n, m, vis, grid)){
                q.push({newr, newc});
                vis[newr][newc] = 1;
            }
        }
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
                bfs(i, j, grid, vis);
                count++;
            }
        }
    }

    return count;
}
