// All the 8 directions movement are allowed. We need to find the number of connected components simply in a grid.

// Simple BFS 
void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& arr, int n, int m){
    vis[row][col] = 1;
    
    queue<pair<int,int>>q;
    q.push({row,col});
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop(); 
        
        // All 8 directions traversal are allowed
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                // We are generating all the possible neighbour nodes that are inside the grid ,are unvisited, has land 
                int nr = i+row;
                int nc = j+col;
                
                // If any such node is found push it into the 'queue' and mark it as 'visited'
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && (vis[nr][nc] == 0) && (arr[nr][nc] == '1')){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    
}

int numIslands(vector<vector<char>>& arr) {
    int n = arr.size(), m = arr[0].size();
    vector<vector<int>>vis(n, vector<int>(m,0));
    
    int count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // If node is not visited and it is a land than we can traverse on it and component connected to it and mark all of them visited
            if((vis[i][j] == 0) && (arr[i][j] == '1')){
                bfs(i, j, vis, arr, n, m);
                count++;
            }
        }
    }
    
    // Total number of connected components
    return count;
}