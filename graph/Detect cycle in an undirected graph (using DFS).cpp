// 'child' aur 'parent' node ko sath me store karna h, agar 'child' node pehle se hi visited h AND, uska parent is different than the current node, tab cycle exist karegi

bool dfs(int node, int parent, vector<int>adj[], vector<int>&vis){
    vis[node] = 1;
    
    for(auto i : adj[node]){
        // 'iterating' node matlab - 'i' ('for' loop ka)
        // agar unvisited h to 'dfs' unvisited node par chalao
        // 'iterating' wali node hamesha 'child' hoti h
        if(!vis[i]){
            if(dfs(i, node, adj, vis))
                return true;
        }
        // agar visited h to check karo ki 'parent' konsi node h,
        // agar 'iterating' node is not equal to 'current' node ka 'parent' than cycle exist karti h

        // agar cycle nahi hoti to - 'iterating' node to 'visited' hi hoti, par yahi node 'current' node ki 'parent' bhi hoti
        else{
            if(i != parent)
                return true;
        }
    }
    
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int n, vector<int> adj[]) {
    // Code here
    vector<int>vis;
    for(int i=0; i < n; i++)
        vis.push_back(0);
    
    for(int i=0; i < n; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis))
                return true;
        }
    }
    
    return false;
}