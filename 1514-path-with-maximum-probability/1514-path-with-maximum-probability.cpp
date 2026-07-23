class Solution {
public:
    vector<double>dijkstra(vector<vector<pair<int,double>>>&adj,int start,int end,int n){
        vector<double>dist(n,0.0);
        priority_queue<pair<double,int>>pq;
        dist[start] = 1.0;
        pq.push({1.0,start});
        while (!pq.empty()){
            double d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d<dist[node]){
                continue;
            }
            for (auto nbr : adj[node]){
                int nbrNode = nbr.first;
                double nbrWt = nbr.second;
                if (dist[nbrNode] < dist[node] * nbrWt) {
                    dist[nbrNode] = dist[node] * nbrWt;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }
        return dist;

    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for (int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double>prob = dijkstra(adj,start_node,end_node,n);
        return prob[end_node];

    }
};