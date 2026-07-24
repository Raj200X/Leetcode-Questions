class Solution {
public:
    bool solve(vector<vector<int>>& adj, int src, int n, vector<bool>& visited,
               stack<int>& st,vector<bool>& pathVis) {
        visited[src] = true;
        pathVis[src] = true;
        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
               if ( solve(adj, nbr, n, visited, st,pathVis)){
                return true;
               }
            }
            else if (pathVis[nbr]) {
            return true;  
        }
        }
        st.push(src);
        pathVis[src] = false;
        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites) {
            int v = edge[0];
            int u = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(numCourses, false);
        stack<int> st;
        vector<bool> pathVis(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (solve(adj, i, numCourses, visited, st,pathVis)){
                    return {};
                }
            }
            
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};