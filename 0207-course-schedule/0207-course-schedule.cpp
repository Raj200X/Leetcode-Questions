class Solution {
public:
    bool topo(int src, vector<bool>& visited, stack<int>& st,
              vector<vector<int>>& adj, vector<bool>& pathvis) {
        visited[src] = true;
        pathvis[src] = true;
        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                if (topo(nbr, visited, st, adj, pathvis))
                    return true;
            } else if (pathvis[nbr]) {
                return true;
            }
        }
        pathvis[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> st;
        vector<bool> visited(numCourses, false);
        vector<vector<int>> adj(numCourses);
        for (auto a : prerequisites) {
            int u = a[1];
            int v = a[0];
            adj[u].push_back(v);
        }
        vector<bool> pathvis(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (topo(i, visited, st, adj, pathvis))
                    return false;
            }
        }
        return true;
    }
};