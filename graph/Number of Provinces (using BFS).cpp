// This question basically asks us to 'count' the number of components present in the graph. 

// Simple BFS 
void bfs(vector<int>adj[], int src, vector<int>& vis){
    queue<int>q;

    q.push(src);
    vis[src] = 1;

    while(!q.empty()){
        int  node = q.front();
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
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
            bfs(adj, i, vis);
            count++;
        }
    }

    return count;
}