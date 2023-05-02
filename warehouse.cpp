int countMinimumUnreachableWerehouse(int warehouse_nodes ,int  warehouse_edges , vector<int> warehouse_from , vector<int> warehouse_to)
{
    vector<vector<int>> graph(warehouse_nodes);
    vector<int> indegree(warehouse_nodes,0);
    
    //creating the graph and calculate the indegree of each node
    for(int i=0; i<warehouse_edges; i++)
    {
        int x = warehouse_from[i]-1 , y = warehouse_to[i] - 1;
        graph[x].push_back(y);
        indegree[y]++;
    }
    
    //if indegree[i] is 0 means no incoming edge hence ans++
    int ans = 0;
    for(int i=0; i<warehouse_nodes; i++)
        if(indegree[i] == 0)
            ans++;
    
   
    return ans;
    
}

int main() {
        int warehouse_nodes = 3;
        int warehouse_edges = 2;
    vector<int> warehouse_from = {1,2};
    vector<int> warehouse_to = {2,1};
    
    cout<<countMinimumUnreachableWerehouse(warehouse_nodes , warehouse_edges , warehouse_from , warehouse_to);
}
