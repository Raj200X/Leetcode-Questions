class Solution {
public:
    bool solve(int V, vector<vector<int>>& adj, vector<bool>& visited,
               int vertex, int destination, int count) {
        
        if (vertex == destination) {
            return true;
        }

        visited[vertex] = true;

        int c = adj[vertex].size();
        for (int i = 0; i < c; i++) {
            if (visited[adj[vertex][i]] == false) {
                if (solve(V, adj, visited, adj[vertex][i], destination, count + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);

        for (int j = 0; j < edges.size(); j++) {
            int ele = edges[j][0];
            adj[ele].push_back(edges[j][1]);
            adj[edges[j][1]].push_back(ele);
        }

        vector<bool> visited(n, false);

        return solve(n, adj, visited, source, destination, 0);
    }
};