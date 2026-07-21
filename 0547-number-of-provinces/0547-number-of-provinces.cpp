class Solution {
public:
    void dfs(int src, vector<vector<int>>& AdjList, vector<bool>& visited) {
        visited[src] = true;
        for (auto nbr : AdjList[src]) {
            if (!visited[nbr]) {
                dfs(nbr, AdjList, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> AdjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    AdjList[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, AdjList, visited);
                cnt++;
            }
        }
        return cnt;
    }
};