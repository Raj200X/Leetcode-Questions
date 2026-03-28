class Solution {
public:
    vector <vector<int>>dp;
    int solve(int &m,int &n,int i,int j){
        if (i==m-1 && j==n-1){
            return 1;
        }
        if (i>=m || j>=n){
            return 0;
        }
        if (dp[i][j]!=-1) return dp[i][j];
        //right
        int right = solve(m,n,i,j+1);
        //down
        int down = solve(m,n,i+1,j);

        return dp[i][j] = right + down;

    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return solve(m,n,0,0);
    }
};