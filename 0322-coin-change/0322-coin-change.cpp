class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&coins , int amount,int i){
        if (amount==0){
            return 0;
        }
        if (i>=coins.size()){
            return INT_MAX;
        }
        if (dp[i][amount]!=-1) return dp[i][amount];
        int pick = INT_MAX;
        int notpick = INT_MAX;
        //pick multiple times
        if (amount>=coins[i]){
            int res = solve(coins,amount-coins[i],i);
            if (res!=INT_MAX){
                pick  = 1+res;
            }
        }
        //not pick
        notpick = solve(coins,amount,i+1);
        
        return dp[i][amount]= min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans =  solve(coins,amount,0);
        if (ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
