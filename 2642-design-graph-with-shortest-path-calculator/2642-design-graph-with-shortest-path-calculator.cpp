class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
    }
    vector<int> dijkstra(vector<vector<pair<int,int>>>&adj,int src,int n){
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while (!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d>dist[node]){
                continue;
            }
            for (auto nbr : adj[node]){
                int nbrNode = nbr.first;
                int nbrWt = nbr.second;
                if (dist[nbrNode] > dist[node] + nbrWt) {
                    dist[nbrNode] = dist[node] + nbrWt;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }
        return dist;
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist =  dijkstra(adj,node1,adj.size());
        if (dist[node2] == INT_MAX)
        return -1;

    return dist[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */