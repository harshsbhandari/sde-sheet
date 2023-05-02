// Course Schedule problem - Topological Sort algorithm ka implementation h
// Topological Sort only applicable to - DAG(Directed Acyclic Graph), matlab is algorithm ko Directed graph me cycle detect karne k liye bhi use kar sakte h

bool bfs(vector<int>adj[], vector<int>& indegree, int n){
    queue<int>q;
    vector<int>ans;

    // Indegree - incoming edges for a particular node is called indegree
    // Jis node ki indegree 0(zero) hogi use sabse pehle complete karna hoga, tabhi (indegree == 0) wali nodes ko 'queue' me push kar dia h
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        // Ab is particular node k adjacent nodes ki indegree reduce karo, (yahan hum bas us particular node ki, uske adjacent nodes se, connecting edges ko erase kar rhe h)
        for(auto i : adj[node]){
            indegree[i]--;

            // Agar indegree zero hui, to is node ko bhi 'queue' me push kar do
            if(indegree[i] == 0)
                q.push(i);
        }
    }

    // Agar 'ans' ka size total number of nodes k barabar h, tabhi topological sort complete hoga, nahi to nahi hoga
    if(ans.size() == n)
        return true;

    return false;
}
bool canFinish(int n, vector<vector<int>>& edges) {
    vector<int>adj[n];
    vector<int>indegree(n, 0);

    // Sabse pehle directed graph ki edges reverse karni h, qki initially
    // first element of 'edges' is dependent h 'second' element of edges
    // matlab 'second' element ko pehle complete karna jaroori h 'first' element se
    for(auto i : edges){
        int u = i[0], v = i[1];

        adj[v].push_back(u);
        indegree[u]++;
    }

    if(bfs(adj, indegree, n))
        return true;
    
    return false;
}