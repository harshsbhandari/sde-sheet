// Ye solution 'source = 0' k liye h

void bfs(int src, vector<int> adj[], vector<int>& vis, vector<int>& ans){
    queue<int>q;
    
    // 'source' node ko queue me push karo, aur 'visited' mark karo
    q.push(src);
    vis[src] = 1;
    
    while(!q.empty()){
        // 'queue' k front ka node nikal lo, aur store kar lo
        int node = q.front();
        q.pop();

        // store kare hue node ko 'ans' me rakho
        ans.push_back(node);
        
        // store kare hue node k adjacent nodes ka traversal karo
        for(auto i : adj[node]){
            // agar wo node 'unvisited' ho tabhi 'queue' me push karo, aur 'visited' mark karo
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    vector<int>ans;
    vector<int>vis(n, 0);

    int src = 0;   
    bfs(src, adj, vis, ans);

    // For all nodes and can also manage disconnected components
    // upper k do line comment kar do agar niche wala 'for' uncomment kia to

    // for(int i = 0; i < n; i++){
    //     if(!vis[i])
    //         bfs(i, adj, vis, ans);
    // }
    
    return ans;
}