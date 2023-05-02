// Basic idea - Graph ki har node ko consider karna h, kisi 1 particular node ko source banao, usme color = '0' fill kardo, taki !color = '1' ho jaye. Ab is source node k adjacent nodes me opposite color fill karo (source node k color k opposite). Aisa karte raho jab tak sab nodes color nahi ho jate, ya phir ye condition fail ho jaye (ki source aur adjacent node ka color hi same ho jaye, ye h condition fail hona)
// Graph ki sari nodes color ho jati h alternating colors me to graph bipartite h


bool dfs(vector<vector<int>>& graph, int src, vector<int>& color, int colors){
    color[src] = colors;

    for(auto i : graph[src]){
        // agar adjacent uncolored h to, color kardo opposite to 'source' node's color (source node ka color == 0, to adjacent node ka color == 1), ie: adjacent node par DFS run kardo (source node se opposite color k liye)
        if(color[i] == -1){
            if(dfs(graph, i, color, !colors))
                return true;
        }
        // agar node colored h to, check karo, agar 'source' node ka color aur 'adjacent' node ka color same h to, 'false' return kardo, graph bipartite nahi h, warna continue ho jayega process aage
        else{
            if(color[i] == color[src])
                return true;
        }
    }

    return false;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    // initially sari nodes ka color '-1' ie: no color
    vector<int>color(n, -1);

    for(int i = 0; i < n; i++){
        // agar node uncolored h to run karo
        if(color[i] == -1){
            // agar adjacent node ka color same h to, 'false' return karo ie: graph is not bipartite
            if(dfs(graph, i, color, 0))
                return false;
        }
    }

    return true;
}