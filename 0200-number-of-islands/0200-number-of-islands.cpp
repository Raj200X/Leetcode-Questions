class Solution {
public:
    // void dfs(vector<vector<char>>& grid,int i,int j,int &m,int &n){
    //     if (i>=m || j>= n || i<0 || j < 0 || grid[i][j]!='1'){
    //         return;
    //     }
    //     grid[i][j] = '2';
    //     dfs(grid,i-1,j,m,n); // top
    //     dfs(grid,i+1,j,m,n); // bottom
    //     dfs(grid,i,j-1,m,n); // left
    //     dfs(grid,i,j+1,m,n); // right
    // }
    void bfs(vector<vector<char>>& grid,queue<int>&rq,queue<int>&cq,int m,int n){
        while(!rq.empty()){
            int row = rq.front();
            int col = cq.front();
            rq.pop();
            cq.pop();
            if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                rq.push(row - 1);
                cq.push(col);
                grid[row - 1][col] = '2';
            }
            if (row + 1 < m && grid[row + 1][col] == '1') {
                rq.push(row + 1);
                cq.push(col);
                grid[row + 1][col] = '2';
            }
            if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                rq.push(row);
                cq.push(col - 1);
                grid[row][col - 1] = '2';
            }
            if (col + 1 < n && grid[row][col + 1] == '1') {
                rq.push(row);
                cq.push(col + 1);
                grid[row][col + 1] = '2';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i =0;i<grid.size();i++){
            for (int j = 0;j<grid[i].size();j++){
                if (grid[i][j]=='1'){
                    queue<int>rq;
                    queue<int>cq;
                    rq.push(i);
                    cq.push(j);
                    bfs(grid,rq,cq,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};