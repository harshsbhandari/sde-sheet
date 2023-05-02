// 'child' aur 'parent' node ko sath me store karna h, agar 'child' node pehle se hi visited h AND, uska parent is different than the current node, tab cycle exist karegi

bool bfs(int src, vector<int>adj[], vector<int>&vis){
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src, -1});
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto i : adj[node]){
            // 'iterating' node matlab - 'i' ('for' loop ka)
            // agar unvisited h to 'queue' me push karo aur visited mark karo
            // 'iterating' wali node hamesha 'child' hoti h
            if(!vis[i]){
                vis[i] = 1;
                q.push({i, node});
            }
            // agar visited h to check karo ki 'parent' konsi node h,
            // agar 'iterating' node is not equal to 'current' node ka 'parent' than cycle exist karti h

            // agar cycle nahi hoti to - 'iterating' node to 'visited' hi hoti, par yahi node 'current' node ki 'parent' bhi hoti
            else{ 
                if(parent != i)
                    return true;
            }
        }
    }
    
    return false;
}

bool isCycle(int n, vector<int> adj[]) {
    // Code here
    vector<int>vis;
    for(int i=0; i < n; i++)
        vis.push_back(0);
    
    for(int i=0; i < n; i++){
        if(!vis[i]){
            if(bfs(i, adj, vis))
                return true;
        }
    }
    
    return false;
}