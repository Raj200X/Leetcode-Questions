class Solution {
public:
    vector<int> Dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n + 1, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;
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
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist = Dijkstra(k, adj, n);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};