void dfs(int src, vector<int> adj[], vector<int>& ans, vector<int>& vis){
    // sabse pehle 'source node' ko 'visited' mark karo aur 'ans' me store karo 
    vis[src] = 1;
    ans.push_back(src);
    
    // 'source' node k adjacent nodes ko traverse karo
    for(auto i : adj[src]){
        // 'unvisited' nodes par 'dfs' chalao
        if(!vis[i])
            dfs(i, adj, ans, vis);
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    vector<int>ans;
    vector<int>vis(n, 0);
    
    // Sare nodes ko traverse karo aur 'unvisited' nodes par 'dfs' function chalao
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i, adj, ans, vis);
    }
    
    return ans;
}