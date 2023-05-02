// It helps us to find shortest path with respect to a 'source' node to all other nodes. Dijkstra does the same thing but, dijkstra fails in graph with negative weights and goes for TLE when graph has a negative cycle, but Bellman-Ford works perfectly fine with negative weights too. It also helps to detect negative cycles in the graph. And Bellman-Ford is only applicable to Directed graph(DG), convert undirected graph(UG) to directed graph(DG) to apply on it.

vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
    // Initially sare nodes unreachable h
    vector<int>dist(n, 1e8);
    // Source hamesha 'zero' hota h
    dist[src] = 0;
    
    // Idea is to relax the nodes for 'n-1' times. Matlab agar node 'v' par hum jaldi(efficiently) reach kar jate h from node 'u', to use update kardo, efficient wale answer se.
    for(int i = 0; i < n-1; i++){
        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            
            // node 'v' from node 'u' efficiently reach kar sakte h to update karo
            if((dist[v] > dist[u]+wt) && dist[u] != 1e8)
                dist[v] = dist[u]+wt;
        }
    }
    
    // Ye checking wala step h, hum 1 baar phir se nodes ko relax karenge, agar (node 'v' from node 'u' efficiently reach kar sakte h) ye condition true ho gyi 1 baar bhi to matlab graph me negative cycle h, qki har iteration me value kam hoti jayegi ie: -ve cycle
    for(auto it : edges){
        int u = it[0], v = it[1], wt = it[2];
        
        if((dist[v] > dist[u]+wt) && dist[u] != 1e8)
            return {-1};
    }
    
    return dist;
}