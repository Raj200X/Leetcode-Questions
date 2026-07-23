class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src, int n) {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, src});
        ways[src] = 1;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node]) {
                continue;
            }
            for (auto nbr : adj[node]) {
                int nbrNode = nbr.first;
                int nbrWt = nbr.second;
                if (dist[nbrNode] > dist[node] + nbrWt) {
                    dist[nbrNode] = dist[node] + nbrWt;
                    ways[nbrNode] = ways[node];
                    pq.push({dist[nbrNode], nbrNode});
                } else if (dist[nbrNode] == dist[node] + nbrWt) {
                    ways[nbrNode] = (ways[nbrNode] + ways[node]) % MOD;
                }
            }
        }
        return ways;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dis = dijkstra(adj, 0, n);
        return dis[n - 1];
    }
};