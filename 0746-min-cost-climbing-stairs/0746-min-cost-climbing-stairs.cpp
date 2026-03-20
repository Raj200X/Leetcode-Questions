class Solution {
public:
    vector <int> dp;
    int solve(vector<int>& cost,int i,int top){
        int n = cost.size();
        if (i >= n) return 0;
        if (dp[i]!=-1){
            return dp[i];
        }
        // i+1
           int  first = solve(cost,i+1,top);
        // i+2
           int second = solve(cost,i+2,top);
        

        return dp[i]=cost[i]+ min(first,second);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int top = cost.size();
        dp.resize(top+1,-1);
        return min(solve(cost,0,top),solve(cost,1,top));
    }
};
