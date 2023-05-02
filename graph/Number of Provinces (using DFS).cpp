// This question basically asks us to 'count' the number of components present in the graph. 

// Simple DFS 
void dfs(vector<int>adj[], int src, vector<int>& vis){
    vis[src] = 1;

    for(auto it : adj[src]){
        if(!vis[it])
            dfs(adj, it, vis);
    }
}

int findCircleNum(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int>adj[n+1];
    vector<int>vis(n+1, 0);
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // (i != j) - to avoid self loops
            if(edges[i][j] == 1 && (i != j)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Traverse through all the nodes, check whether if it is 'visited' or not, if not 'visited' than traverse all its connected nodes mark them visited and consider it in that same component.
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(adj, i, vis);
            count++;
        }
    }

    return count;
}