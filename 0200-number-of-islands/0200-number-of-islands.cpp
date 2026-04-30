class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j,int &m,int &n){
        if (i>=m || j>= n || i<0 || j < 0 || grid[i][j]!='1'){
            return;
        }
        grid[i][j] = '2';
        dfs(grid,i-1,j,m,n); // top
        dfs(grid,i+1,j,m,n); // bottom
        dfs(grid,i,j-1,m,n); // left
        dfs(grid,i,j+1,m,n); // right
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i =0;i<grid.size();i++){
            for (int j = 0;j<grid[i].size();j++){
                if (grid[i][j]=='1'){
                    dfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};