class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&squares,int i,int n){
        if (n==0){
            return 0;   
        }
        if (i>=(int)squares.size()){
            return INT_MAX;
        }
        if (n<0){
            return INT_MAX;
        }
        if (dp[i][n]!=-1){
            return dp[i][n];
        }
        int pick = INT_MAX;
        int res = solve(squares,i,n-squares[i]);
        if (res!=INT_MAX){
            pick = res + 1;
        }
        int notPick = solve(squares,i+1,n);
        return dp[i][n] = min(pick,notPick);

    }
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i*i <= n; i++){
            squares.push_back(i*i);
        }
        dp.assign(squares.size()+1, vector<int>(n+1,-1));
        return solve(squares,0,n);
    }
};