class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins,int amount,int i){
        // base case;
        if (amount==0){
            return 1;
        }
        if (i>=coins.size()){
            return 0;
        }
        if (dp[i][amount]!=-1) return dp[i][amount];
        int pick =0 ;
        int notpick =0 ;

        //pick
        if (coins[i]<=amount){
            pick = solve(coins,amount-coins[i],i);
        }

        //not pick
        notpick = solve(coins,amount,i+1);

        return dp[i][amount] = pick+notpick;



    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return solve(coins,amount,0);
    }
};