// Floyd Warshall - It is also called multi-source shortest path algorithm. Dijkstra & Bellman is single source shortest path algorithm. Floyd Warshall also helps to detect negative cycle in a graph. Works with both directed and undirected graphs.

void shortest_distance(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // -1 matlab unreachable, to ise 'infinite' value se replace kardo
            if(arr[i][j] == -1)
                arr[i][j] = 1e9;
                
            // when (source == destination) tab distance to travel 0(zero) hi hoga
            else if(i == j)
                arr[i][j] = 0;
        }
    }
    
    //  Here we compute shortest path to reach every node considering all node as the source one at a time.
    //  via - konse node se hoke
    //  u - source node
    //  v - destination node
    //  Basically yaha hum brute-force apply kar rhe h, aur check kar rhe h ki kya aisi koi node h(via), jiske through hum 'source' se 'destination' tak pahuche to wo most efficient answer hoga, agar h to update kar do
    for(int via = 0; via < n; via++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < m; v++)
                // arr[u][v] = ('source' se 'via' tak) + ('via' se 'destination' tak)
                arr[u][v] = min(arr[u][v], arr[u][via]+arr[via][v]);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(arr[i][i] < 0)
        //  -ve cycle exists (qki, wo node source == 'u' se destination == 'u' par '0'(zero) se kam value par pahunch jara h)
    }
    
    // unreachable nodes par 'infinite' ki jagah '-1'
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1e9)
                arr[i][j] = -1;
        }
    }
    
}