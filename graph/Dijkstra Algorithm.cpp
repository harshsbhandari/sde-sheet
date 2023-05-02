// Shortest path relate problems k liye use karte h, dijkstra ka, agar graph me negative cycle h to ye kaam nahi karega (Infinity loop me rhe jayega), sirf positive weighted graph me use ho sakta h ye 

vector <int> dijkstra(int n, vector<vector<int>> adj[], int src){

    // Initially set all the nodes to (INT_MAX ie : infinity). Matlab koi bhi reachable nahi h
    vector<int>dist(n, INT_MAX);
    // 'set' use isliye kar rhe h qki, ye hamesha 'min' element begin me rakhta h
    // {distance, node} - is format me h
    set<pair<int, int>>st;

    // sabse pehle 'src' ka distance = 0 karo, qki start hi yahan se kar rhe h
    dist[src] = 0;
    // aur phir {0, src} ko 'set' me push kardo (qki yhi se begin kar rhe h)
    st.insert({0, src});

    // BFS type ka algorithm h, 'set' k front se element nikalna h, check karna h, kya is element k adjacent wala node hum kam-se-kam kitne distance me pahuch sakte h 
    while(!st.empty()){
        auto it = *(st.begin());
        int distance = it.first;
        int node = it.second;
        st.erase(it);
        
        // adjacent node ka traversal karna h  
        for(auto i : adj[node]){
            int adjNode = i[0];
            int adjNodeWeight = i[1];
            
            // check karna h, kya adjacent node ki value jyada h, current aur adjacent node k sum se, agar aisa h to humko adjacent node k distance ko change karna h, kam wali value se
            if(dist[adjNode] > adjNodeWeight+distance){
                
                // agar adjacent node ka distance INT_MAX nhi h, matlab ise pehele kisine visit kia h, par ye optimum answer nahi de payega, isliye is value to hum 'set' se nikal dete h
                if(dist[adjNode] != INT_MAX)
                    st.erase({dist[adjNode], adjNode});
                
                // aur ye humne update kar lia kam wali value se, aur ise 'set' me bhi insert kar dia
                dist[adjNode] = adjNodeWeight+distance;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    
    return dist;
}